// Problem: Max Sum Subarray of Size K
// Pattern: Fixed-Size Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        if (n < k) return 0;

        int windowSum = 0;

        // Calculate sum of first window
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }
        int maxSum = windowSum;

        // Slide the window across the array
        for (int i = k; i < n; i++) {
            windowSum += arr[i] - arr[i - k];
            maxSum = max(maxSum, windowSum);
        }

        return maxSum;
    }
};