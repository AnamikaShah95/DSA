#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long totalCandies = 0;
        int maxCandy = 0;
        
        for (int candy : candies) {
            totalCandies += candy;
            maxCandy = max(maxCandy, candy);
        }
        
        // If total candies are fewer than k, it's impossible to give 1 candy to each child
        if (totalCandies < k) {
            return 0;
        }
        
        int low = 1, high = maxCandy;
        int ans = 0;
        
        // Binary Search on Answer
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Calculate how many children can get 'mid' candies
            long long childrenServed = 0;
            for (int candy : candies) {
                childrenServed += (candy / mid);
            }
            
            if (childrenServed >= k) {
                ans = mid;      // Feasible answer, try to maximize
                low = mid + 1;
            } else {
                high = mid - 1; // Too many candies per child, reduce candidate size
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> candies1 = {5, 8, 6};
    long long k1 = 3;

    vector<int> candies2 = {2, 5};
    long long k2 = 11;

    cout << "Max Candies per Child (Example 1): " << sol.maximumCandies(candies1, k1) << endl; // Output: 5
    cout << "Max Candies per Child (Example 2): " << sol.maximumCandies(candies2, k2) << endl; // Output: 0

    return 0;
}