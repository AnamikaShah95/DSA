#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string result = "";
        for (char c : s) {
            if (!result.empty() && result.back() == c) {
                result.pop_back(); // Remove the adjacent duplicate
            } else {
                result.push_back(c); // Add non-duplicate character
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    string input = "abbaca";
    
    cout << "Original String: " << input << endl;
    cout << "After Removing Duplicates: " << sol.removeDuplicates(input) << endl; // Output: "ca"

    return 0;
}