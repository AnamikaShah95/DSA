#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            // Push expected closing brackets onto the stack when encountering opening brackets
            if (c == '(') {
                st.push(')');
            } else if (c == '{') {
                st.push('}');
            } else if (c == '[') {
                st.push(']');
            } else {
                // If stack is empty or the top doesn't match current closing bracket
                if (st.empty() || st.top() != c) {
                    return false;
                }
                st.pop();
            }
        }
        
        // Return true only if all opening brackets have been matched
        return st.empty();
    }
};

int main() {
    Solution sol;
    string s1 = "()[]{}";
    string s2 = "(]";

    cout << "Is \"" << s1 << "\" valid? " << (sol.isValid(s1) ? "true" : "false") << endl; // Output: true
    cout << "Is \"" << s2 << "\" valid? " << (sol.isValid(s2) ? "true" : "false") << endl; // Output: false

    return 0;
}