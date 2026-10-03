#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // If mid element is greater than high element, 
            // the min element must be in the right subarray
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } 
            // Otherwise, min element is at mid or in the left subarray
            else {
                high = mid;
            }
        }

        return nums[low];
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {3, 4, 5, 1, 2};
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};

    cout << "Min in nums1: " << sol.findMin(nums1) << endl; // Output: 1
    cout << "Min in nums2: " << sol.findMin(nums2) << endl; // Output: 0

    return 0;
}