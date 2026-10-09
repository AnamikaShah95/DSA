#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool canShip(const vector<int>& weights, int days, int capacity) {
        int daysNeeded = 1;
        int currentWeight = 0;

        for (int w : weights) {
            if (currentWeight + w > capacity) {
                daysNeeded++;
                currentWeight = 0;
            }
            currentWeight += w;
        }

        return daysNeeded <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (canShip(weights, days, mid)) {
                high = mid; // Try searching for a smaller valid capacity
            } else {
                low = mid + 1; // Increase capacity
            }
        }

        return low;
    }
};

int main() {
    Solution sol;
    vector<int> weights1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days1 = 5;

    vector<int> weights2 = {3, 2, 2, 4, 1, 4};
    int days2 = 3;

    cout << "Min Capacity (Example 1): " << sol.shipWithinDays(weights1, days1) << endl; // Output: 15
    cout << "Min Capacity (Example 2): " << sol.shipWithinDays(weights2, days2) << endl; // Output: 6

    return 0;
}