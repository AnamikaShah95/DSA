#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxKadane = nums[0], currentMax = 0;
        int minKadane = nums[0], currentMin = 0;

        for (int num : nums) {
            totalSum += num;

            // Standard Kadane's for Maximum Subarray Sum
            currentMax = max(num, currentMax + num);
            maxKadane = max(maxKadane, currentMax);

            // Modified Kadane's for Minimum Subarray Sum
            currentMin = min(num, currentMin + num);
            minKadane = min(minKadane, currentMin);
        }

        // If all elements are negative, return the maximum single element
        if (maxKadane < 0) {
            return maxKadane;
        }

        return max(maxKadane, totalSum - minKadane);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, -3, 5};

    cout << "Max Circular Subarray Sum: " << sol.maxSubarraySumCircular(nums) << endl; // Output: 10 (5 + 5)

    return 0;
}