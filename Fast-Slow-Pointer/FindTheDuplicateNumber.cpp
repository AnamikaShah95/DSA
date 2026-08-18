#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Step 1: Detect the intersection point in the cycle
        int slow = nums[0];
        int fast = nums[0];
        
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        // Step 2: Find the entrance to the cycle (duplicate element)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 4, 2, 2};
    
    cout << "Duplicate Number: " << sol.findDuplicate(nums) << endl; // Output: 2

    return 0;
}