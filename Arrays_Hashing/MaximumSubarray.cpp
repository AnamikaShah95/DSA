#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestending = nums[0];
        int ans = nums[0];
        
        for (size_t i = 1; i < nums.size(); i++) {
            bestending = max(nums[i], bestending + nums[i]);
            ans = max(ans, bestending);
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Maximum Subarray Sum: " << sol.maxSubArray(nums) << endl; // Output: 6

    return 0;
}