// Problem: Count Triplets with Sum Smaller than X (GeeksforGeeks)
// Link: https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1
// Time Complexity: O(n^2)
// Space Complexity: O(1) auxiliary space (excluding O(log n) sorting)

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countTriplets(int sum, vector<int>& arr) {
        int n = arr.size();
        long long count = 0;
        
        // 1. Sort the array to use two pointers
        sort(arr.begin(), arr.end());
        
        // 2. Fix the first element one by one
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;
            
            // 3. Two pointer approach for remaining elements
            while (j < k) {
                // If sum of current triplet is smaller than given sum
                if (arr[i] + arr[j] + arr[k] < sum) {
                    // All elements between j and k will also form valid triplets
                    count += (k - j);
                    j++; // Move left pointer right to try larger elements
                } else {
                    k--; // Move right pointer left to decrease the sum
                }
            }
        }
        
        return count;
    }
};