#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        
        // Count the frequency of each character
        for (char c : s) {
            count[c - 'a']++;
        }
        
        // Find the index of the first character with a count of 1
        for (int i = 0; i < s.length(); i++) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};

int main() {
    Solution sol;
    string s1 = "leetcode";
    string s2 = "loveleetcode";

    cout << "Input: \"" << s1 << "\" -> First Unique Index: " << sol.firstUniqChar(s1) << endl; // Output: 0
    cout << "Input: \"" << s2 << "\" -> First Unique Index: " << sol.firstUniqChar(s2) << endl; // Output: 2

    return 0;
}