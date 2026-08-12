// Problem: Longest Repeating Character Replacement (LeetCode #424)
// Link: https://leetcode.com/problems/longest-repeating-character-replacement/
// Pattern: Variable-Size Sliding Window + Frequency Array
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
private:
    int findMaxFreq(const vector<int>& freq) {
        int maxc = -1;
        for (int i = 0; i < 256; i++) {
            maxc = max(maxc, freq[i]);
        }
        return maxc;
    }

public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> f(256, 0);
        int low = 0, high = 0, res = INT_MIN;

        for (high = 0; high < n; high++) {
            f[s[high]]++;
            int maxcnt = findMaxFreq(f);
            int len = high - low + 1;
            int diff = len - maxcnt;

            // Shrink window if required replacements exceed k
            while (diff > k) {
                f[s[low]]--;
                low++;
                maxcnt = findMaxFreq(f);
                len = high - low + 1;
                diff = len - maxcnt;
            }

            len = high - low + 1;
            res = max(res, len);
        }

        return (res == INT_MIN) ? 0 : res;
    }
};