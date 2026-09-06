#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].length();
        int numWords = words.size();
        int totalLen = wordLen * numWords;
        int sLen = s.length();

        if (sLen < totalLen) return result;

        // Count frequencies of all target words
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }

        // Run sliding window for all possible offsets [0, wordLen - 1]
        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i;
            unordered_map<string, int> seen;
            int count = 0; // Number of valid words matched so far

            while (right + wordLen <= sLen) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordCount.count(word)) {
                    seen[word]++;
                    count++;

                    // If word frequency exceeds target, shrink window from left
                    while (seen[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    // Found a valid substring containing all words
                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    // Invalid word encountered; reset window state
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    vector<int> indices = sol.findSubstring(s, words);
    cout << "Concatenated Substring Indices: ";
    for (int idx : indices) {
        cout << idx << " "; // Output: 0 9
    }
    cout << endl;

    return 0;
}