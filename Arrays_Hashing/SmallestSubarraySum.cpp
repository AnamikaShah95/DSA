#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubarraySum(vector<int> &nums) {
        int bestending = nums[0];
        int ans = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            bestending = min(nums[i], bestending + nums[i]);
            ans = min(ans, bestending);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, -4, 2, -3, -1, 7, -5};

    cout << "Smallest Subarray Sum: " << sol.minSubarraySum(nums) << endl; // Output: -6 (-4 + 2 + -3 + -1)

    return 0;
}