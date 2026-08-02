// Problem: 3Sum (LeetCode #15)
// Link: https://leetcode.com/problems/3sum/
// Time Complexity: O(n^2)
// Space Complexity: O(1) auxiliary space (excluding output space)

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; ++i) {
            // If the current number is > 0, no 3 numbers can sum to 0
            if (nums[i] > 0) break;

            // Skip duplicate elements for the first position
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int total = nums[i] + nums[left] + nums[right];

                if (total < 0) {
                    left++;
                } else if (total > 0) {
                    right--;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    // Skip duplicate elements for second and third positions
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }

        return res;
    }
};