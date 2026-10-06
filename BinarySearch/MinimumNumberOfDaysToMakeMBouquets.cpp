#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool canMake(const vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int flowers = 0;

        for (int b : bloomDay) {
            if (b <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0; // Reset for next bouquet
                }
            } else {
                flowers = 0; // Break adjacency
            }
        }

        return bouquets >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        // Prevent integer overflow during multiplication
        if ((long long)m * k > n) {
            return -1;
        }

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMake(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1; // Try to find a smaller feasible day
            } else {
                low = mid + 1;  // Need more days for flowers to bloom
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> bloomDay1 = {1, 10, 3, 10, 2};
    int m1 = 3, k1 = 1;

    vector<int> bloomDay2 = {1, 10, 3, 10, 2};
    int m2 = 3, k2 = 2;

    cout << "Min days (Example 1): " << sol.minDays(bloomDay1, m1, k1) << endl; // Output: 3
    cout << "Min days (Example 2): " << sol.minDays(bloomDay2, m2, k2) << endl; // Output: -1

    return 0;
}