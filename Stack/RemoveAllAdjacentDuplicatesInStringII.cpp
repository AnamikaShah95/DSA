#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        // Stack stores pairs of {character, consecutive_count}
        vector<pair<char, int>> st;

        for (char c : s) {
            if (!st.empty() && st.back().first == c) {
                st.back().second++; // Increment count if same character
            } else {
                st.push_back({c, 1}); // Push new character with count 1
            }

            // If character count reaches k, pop it from stack
            if (st.back().second == k) {
                st.pop_back();
            }
        }

        // Reconstruct the final string
        string result = "";
        for (const auto& p : st) {
            result.append(p.second, p.first);
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s = "deeedbbcccbdaa";
    int k = 3;

    cout << "Original String: " << s << endl;
    cout << "After Removing " << k << "-Adjacent Duplicates: " << sol.removeDuplicates(s, k) << endl; // Output: "aa"

    return 0;
}