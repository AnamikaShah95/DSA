#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_val = INT_MIN, min_val = INT_MAX;
        int start = -1, end = -2; // Default handles the already-sorted case

        // Single pass to locate both boundary edges
        for (int i = 0; i < n; ++i) {
            max_val = max(max_val, nums[i]);
            if (nums[i] < max_val) {
                end = i;
            }

            int j = n - 1 - i;
            min_val = min(min_val, nums[j]);
            if (nums[j] > min_val) {
                start = j;
            }
        }

        return end - start + 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};

    cout << "Shortest Unsorted Subarray Length: " << sol.findUnsortedSubarray(nums) << endl; // Output: 5 ([6, 4, 8, 10, 9])

    return 0;
}