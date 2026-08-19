#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int max_len = 0;
        int zero_count = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                zero_count++;
            }

            // Shrink window if zero count exceeds k
            while (zero_count > k) {
                if (nums[left] == 0) {
                    zero_count--;
                }
                left++;
            }

            // Update max consecutive ones window length
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    cout << "Max Consecutive Ones: " << sol.longestOnes(nums, k) << endl; // Output: 6

    return 0;
}