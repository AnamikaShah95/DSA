#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long low = 0, high = 0;
        for (int num : nums) {
            low = max(low, (long long)num);
            high += num;
        }

        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isValid(nums, k, mid)) {
                ans = mid;
                high = mid - 1; // Try to find a smaller maximum sum
            } else {
                low = mid + 1; // Increase the allowed sum
            }
        }

        return ans;
    }

private:
    bool isValid(vector<int>& nums, int k, long long maxSum) {
        int subarrays = 1;
        long long currentSum = 0;

        for (int num : nums) {
            if (currentSum + num <= maxSum) {
                currentSum += num;
            } else {
                subarrays++;
                currentSum = num;
            }
        }

        return subarrays <= k;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {7, 2, 5, 10, 8};
    int k1 = 2;

    vector<int> nums2 = {1, 2, 3, 4, 5};
    int k2 = 2;

    cout << "Split Array Largest Sum (Example 1): " << sol.splitArray(nums1, k1) << endl; // Output: 18
    cout << "Split Array Largest Sum (Example 2): " << sol.splitArray(nums2, k2) << endl; // Output: 9

    return 0;
}