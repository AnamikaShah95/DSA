#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Frequency array to store counts of remainder occurrences.
        // Size k because remainders modulo k range from 0 to k-1.
        vector<int> remainderCount(k, 0);
        
        // Base case: a prefix sum of 0 has a remainder of 0 once before starting.
        remainderCount[0] = 1;
        
        int runningSum = 0;
        int count = 0;
        
        for (int num : nums) {
            runningSum += num;
            
            // Normalize remainder to be strictly non-negative
            int remainder = (runningSum % k + k) % k;
            
            // Increment total valid subarrays by previous occurrences of this remainder
            count += remainderCount[remainder];
            
            // Increment the frequency for this remainder
            remainderCount[remainder]++;
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    cout << "Subarrays Divisible by " << k << ": " << sol.subarraysDivByK(nums, k) << endl; // Output: 7

    return 0;
}