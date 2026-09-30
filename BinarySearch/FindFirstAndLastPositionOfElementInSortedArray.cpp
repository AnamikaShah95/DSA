#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findBound(nums, target, true), findBound(nums, target, false)};
    }

private:
    int findBound(const vector<int>& nums, int target, bool isFirst) {
        int left = 0, right = nums.size() - 1;
        int bound = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                bound = mid;
                if (isFirst) {
                    right = mid - 1; // Keep searching in the left half for first position
                } else {
                    left = mid + 1;  // Keep searching in the right half for last position
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return bound;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    int target2 = 6;

    vector<int> res1 = sol.searchRange(nums, target1);
    vector<int> res2 = sol.searchRange(nums, target2);

    cout << "Range for target " << target1 << ": [" << res1[0] << ", " << res1[1] << "]" << endl; // Output: [3, 4]
    cout << "Range for target " << target2 << ": [" << res2[0] << ", " << res2[1] << "]" << endl; // Output: [-1, -1]

    return 0;
}