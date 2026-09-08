#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        return mergeSortCount(prefix, 0, n + 1, lower, upper);
    }

private:
    int mergeSortCount(vector<long long>& prefix, int left, int right, int lower, int upper) {
        if (right - left <= 1) return 0;
        
        int mid = left + (right - left) / 2;
        int count = mergeSortCount(prefix, left, mid, lower, upper) + 
                    mergeSortCount(prefix, mid, right, lower, upper);
        
        // Two pointers on sorted right subarray
        int j = mid, k = mid;
        for (int i = left; i < mid; ++i) {
            while (j < right && prefix[j] - prefix[i] < lower) j++;
            while (k < right && prefix[k] - prefix[i] <= upper) k++;
            count += (k - j);
        }
        
        // Standard merge operation to maintain sorted order
        vector<long long> sorted(right - left);
        int p1 = left, p2 = mid, idx = 0;
        while (p1 < mid && p2 < right) {
            if (prefix[p1] <= prefix[p2]) sorted[idx++] = prefix[p1++];
            else sorted[idx++] = prefix[p2++];
        }
        while (p1 < mid) sorted[idx++] = prefix[p1++];
        while (p2 < right) sorted[idx++] = prefix[p2++];
        
        for (int i = 0; i < sorted.size(); ++i) {
            prefix[left + i] = sorted[i];
        }
        
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2, 5, -1};
    int lower = -2, upper = 2;

    cout << "Range Sum Count: " << sol.countRangeSum(nums, lower, upper) << endl; // Output: 3

    return 0;
}