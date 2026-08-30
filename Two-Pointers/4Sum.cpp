#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4) return ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            // Avoid duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                // Avoid duplicates for the second number
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    // Use long long to avoid integer overflow
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Skip duplicates for the third and fourth numbers
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> result = sol.fourSum(nums, target);
    for (const auto& quad : result) {
        cout << "[" << quad[0] << ", " << quad[1] << ", " << quad[2] << ", " << quad[3] << "]\n";
    }

    return 0;
}