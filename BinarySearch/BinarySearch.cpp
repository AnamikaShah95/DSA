#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    int target2 = 2;

    cout << "Target " << target1 << " found at index: " << sol.search(nums, target1) << endl; // Output: 4
    cout << "Target " << target2 << " found at index: " << sol.search(nums, target2) << endl; // Output: -1

    return 0;
}