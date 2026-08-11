// Problem: Fruit Into Baskets (LeetCode #904)
// Link: https://leetcode.com/problems/fruit-into-baskets/
// Pattern: Variable-Size Sliding Window + Frequency Map (At most 2 distinct types)
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> f;
        int low = 0, high = 0;
        int n = fruits.size();
        int res = 0;

        for (high = 0; high < n; high++) {
            f[fruits[high]]++;

            // Shrink window if distinct fruit types exceed 2
            while (f.size() > 2) {
                f[fruits[low]]--;
                if (f[fruits[low]] == 0) {
                    f.erase(fruits[low]);
                }
                low++;
            }

            int len = high - low + 1;
            res = max(res, len);
        }

        return res;
    }
};