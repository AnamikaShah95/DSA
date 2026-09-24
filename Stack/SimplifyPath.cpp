#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string token;

        // Split the path by '/'
        while (getline(ss, token, '/')) {
            // Ignore empty strings (from multiple slashes like "//") and current directory "."
            if (token == "" || token == ".") {
                continue;
            }
            // Go up one directory for ".."
            if (token == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } 
            // Valid directory or file name (including "...", "....", etc.)
            else {
                stack.push_back(token);
            }
        }

        // Reconstruct the simplified canonical path
        string result = "";
        for (const string& dir : stack) {
            result += "/" + dir;
        }

        // Return "/" if stack was empty, otherwise return the reconstructed path
        return result.empty() ? "/" : result;
    }
};

int main() {
    Solution sol;
    string path1 = "/home//foo/";
    string path2 = "/a/./b/../../c/";

    cout << "Original: " << path1 << " -> Canonical: " << sol.simplifyPath(path1) << endl; // Output: "/home/foo"
    cout << "Original: " << path2 << " -> Canonical: " << sol.simplifyPath(path2) << endl; // Output: "/c"

    return 0;
}