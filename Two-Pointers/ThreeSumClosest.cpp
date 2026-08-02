// Problem: 3Sum Closest (LeetCode #16)
// Link: https://leetcode.com/problems/3sum-closest/
// Time Complexity: O(n^2)
// Space Complexity: O(1) auxiliary space (excluding O(log n) space used for sorting)

#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        // Sort the array to use two pointers
        std::sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // If we found an exact match, return target immediately
                if (currentSum == target) {
                    return target;
                }
                
                // Update closestSum if currentSum is closer to target
                if (std::abs(target - currentSum) < std::abs(target - closestSum)) {
                    closestSum = currentSum;
                }
                
                // Adjust pointers based on currentSum comparison with target
                if (currentSum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        
        return closestSum;
    }
};