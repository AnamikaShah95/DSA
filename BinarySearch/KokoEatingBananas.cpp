#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            long long hours = 0;
            for (int pile : piles) {
                hours += (pile + mid - 1LL) / mid;
            }

            if (hours <= h) {
                ans = mid;
                high = mid - 1; // Try finding a smaller valid speed
            } else {
                low = mid + 1;  // Speed is too slow
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> piles1 = {3, 6, 7, 11};
    int h1 = 8;

    vector<int> piles2 = {30, 11, 23, 4, 20};
    int h2 = 5;

    cout << "Min Eating Speed (Example 1): " << sol.minEatingSpeed(piles1, h1) << endl; // Output: 4
    cout << "Min Eating Speed (Example 2): " << sol.minEatingSpeed(piles2, h2) << endl; // Output: 30

    return 0;
}