#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.length();
        int pLen = p.length();
        
        if (sLen < pLen) return {};

        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);
        vector<int> result;

        // Initialize frequency counts for p and the first window in s
        for (int i = 0; i < pLen; i++) {
            pCount[p[i] - 'a']++;
            sCount[s[i] - 'a']++;
        }

        // Check the first window
        if (pCount == sCount) {
            result.push_back(0);
        }

        // Slide the window across s
        for (int i = pLen; i < sLen; i++) {
            // Add new character on the right
            sCount[s[i] - 'a']++;
            // Remove character on the left
            sCount[s[i - pLen] - 'a']--;

            // Compare frequency counts
            if (pCount == sCount) {
                result.push_back(i - pLen + 1);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s = "cbaebabacd", p = "abc";

    vector<int> indices = sol.findAnagrams(s, p);
    cout << "Anagram Start Indices: ";
    for (int idx : indices) {
        cout << idx << " "; // Output: 0 6
    }
    cout << endl;

    return 0;
}