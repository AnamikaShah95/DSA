#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
private:
    // Helper function to check if the current window satisfies requirements
    bool isValid(const vector<int>& have, const vector<int>& need) {
        for (int i = 0; i < 256; i++) {
            if (have[i] < need[i]) {
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if (n < m) return "";

        vector<int> have(256, 0);
        vector<int> need(256, 0);

        for (char c : t) {
            need[c]++;
        }

        int low = 0;
        int minLen = INT_MAX;
        int startIdx = -1;

        for (int high = 0; high < n; high++) {
            have[s[high]]++;

            // Shrink window from left while it's valid to find the minimum length
            while (isValid(have, need)) {
                int currentLen = high - low + 1;
                if (currentLen < minLen) {
                    minLen = currentLen;
                    startIdx = low;
                }

                have[s[low]]--;
                low++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};

int main() {
    Solution sol;
    string s = "ADOBECODEBANC", t = "ABC";
    
    cout << "Minimum Window Substring: \"" << sol.minWindow(s, t) << "\"" << endl; 
    // Output: "BANC"

    return 0;
}