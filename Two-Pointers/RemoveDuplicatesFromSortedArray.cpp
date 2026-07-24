// Problem: Remove Duplicates from Sorted Array (LeetCode #26)
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0; // Pointer for the position of unique elements
        int x = 1; // Fast pointer scanning through the array
        int n = nums.size();

        while (x < n) {
            if (nums[x] == nums[x - 1]) {
                x++;
                continue;
            }
            nums[i + 1] = nums[x];
            i++;
            x++;
        }
        return i + 1; // Length of the array with unique elements
    }
};