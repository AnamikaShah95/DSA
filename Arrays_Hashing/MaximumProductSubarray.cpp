#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minending = nums[0];
        int maxending = nums[0];
        int res = nums[0];

        for (int i = 1; i < n; i++) {
            int v1 = nums[i];
            int v2 = minending * nums[i];
            int v3 = maxending * nums[i];

            maxending = max({v1, v2, v3});
            minending = min({v1, v2, v3});

            res = max(res, maxending);
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, -2, 4};

    cout << "Maximum Product Subarray: " << sol.maxProduct(nums) << endl; // Output: 6

    return 0;
}