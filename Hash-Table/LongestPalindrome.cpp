#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        
        int length = 0;
        bool hasOdd = false;
        
        for (auto& pair : count) {
            if (pair.second % 2 == 0) {
                length += pair.second;
            } else {
                length += pair.second - 1; // Add the even portion
                hasOdd = true;             // Mark that a center character is available
            }
        }
        
        if (hasOdd) {
            length += 1; // Add 1 for the center character
        }
        
        return length;
    }
};

int main() {
    Solution sol;
    string s1 = "abccccdd";
    string s2 = "a";

    cout << "Input: \"" << s1 << "\" -> Longest Palindrome Length: " << sol.longestPalindrome(s1) << endl; // Output: 7 ("dccaccd")
    cout << "Input: \"" << s2 << "\" -> Longest Palindrome Length: " << sol.longestPalindrome(s2) << endl; // Output: 1

    return 0;
}