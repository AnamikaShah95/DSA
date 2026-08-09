// Problem: Minimum Size Subarray Sum (LeetCode #209)
// Link: https://leetcode.com/problems/minimum-size-subarray-sum/
// Pattern: Dynamic / Variable-Size Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < n; ++right) {
            sum += nums[right];

            // Shrink window while the current sum meets or exceeds target
            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                ++left;
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};