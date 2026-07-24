// Problem: Remove Duplicates from Sorted Array II (LeetCode #80)
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }

        int i = 2; // Write pointer
        int x = 2; // Read pointer
        int n = nums.size();

        while (x < n) {
            if (nums[x] == nums[i - 2]) {
                x++;
                continue;
            }
            nums[i] = nums[x];
            i++;
            x++;
        }
        return i;
    }
};