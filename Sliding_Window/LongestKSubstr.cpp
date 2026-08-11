// Problem: Longest Substring with Exactly K Unique Characters (GeeksforGeeks)
// Link: https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
// Pattern: Variable-Size Sliding Window + Frequency Map
// Time Complexity: O(n)
// Space Complexity: O(k)

#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int low = 0, high = 0;
        int res = INT_MIN;
        int n = s.size();
        unordered_map<char, int> f;

        for (high = 0; high < n; high++) {
            f[s[high]]++;

            // Shrink window if unique characters exceed k
            while (f.size() > k) {
                f[s[low]]--;
                if (f[s[low]] == 0) {
                    f.erase(s[low]);
                }
                low++;
            }

            // Update result only when unique characters equal k
            if (f.size() == k) {
                int len = high - low + 1;
                res = max(res, len);
            }
        }

        return (res == INT_MIN) ? -1 : res;
    }
};