#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_counts;
        prefix_counts[0] = 1; // Base case: prefix sum of 0 has occurred once
        
        int current_sum = 0;
        int total_subarrays = 0;
        
        for (int num : nums) {
            current_sum += num;
            
            // Check if there exists a prefix sum such that current_sum - prefix_sum = k
            if (prefix_counts.count(current_sum - k)) {
                total_subarrays += prefix_counts[current_sum - k];
            }
            
            // Record the current prefix sum count
            prefix_counts[current_sum]++;
        }
        
        return total_subarrays;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1};
    int k = 2;

    cout << "Total Subarrays: " << sol.subarraySum(nums, k) << endl; // Output: 2

    return 0;
}