#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        
        for (int x : nums) {
            totalSum += x;
        }

        int leftSum = 0;
        for (int i = 0; i < n; ++i) {
            int rightSum = totalSum - leftSum - nums[i];
            
            if (leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 7, 3, 6, 5, 6};

    cout << "Pivot Index: " << sol.pivotIndex(nums) << endl; // Output: 3 (left sum = 1+7+3 = 11, right sum = 5+6 = 11)

    return 0;
}