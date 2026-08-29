#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefix_map;
        prefix_map[0] = -1; // Base case: running sum 0 occurs at virtual index -1
        
        int max_len = 0;
        int running_sum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Treat 0 as -1 and 1 as +1
            running_sum += (nums[i] == 1) ? 1 : -1;
            
            if (prefix_map.find(running_sum) != prefix_map.end()) {
                // Compute distance from first occurrence of this running sum
                max_len = max(max_len, i - prefix_map[running_sum]);
            } else {
                // Record first occurrence only (greedy approach for max length)
                prefix_map[running_sum] = i;
            }
        }
        
        return max_len;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 1, 1, 1, 0, 0};

    cout << "Max Length: " << sol.findMaxLength(nums) << endl; // Output: 8

    return 0;
}