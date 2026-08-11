// Problem: Longest Substring Without Repeating Characters (LeetCode #3)
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Pattern: Variable-Size Sliding Window + Frequency Map
// Time Complexity: O(n)
// Space Complexity: O(min(n, m)) where m is the size of the character set

#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int low = 0, high = 0;
        int res = INT_MIN;
        unordered_map<char, int> f;

        for (high = 0; high < n; high++) {
            f[s[high]]++;
            int len = high - low + 1;

            // Shrink window while duplicate characters exist
            while (f.size() < len) {
                f[s[low]]--;
                if (f[s[low]] == 0) {
                    f.erase(s[low]);
                }
                low++;
                len = high - low + 1;
            }

            res = max(res, len);
        }

        if (res == INT_MIN) return 0;
        return res;
    }
};