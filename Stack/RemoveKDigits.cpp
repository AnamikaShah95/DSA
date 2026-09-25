#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        
        for (char c : num) {
            // Remove larger digits from the end of our candidate string
            while (!result.empty() && k > 0 && result.back() > c) {
                result.pop_back();
                k--;
            }
            result.push_back(c);
        }
        
        // If k > 0, remove remaining digits from the right
        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }
        
        // Remove leading zeros
        int start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        }
        
        result = result.substr(start);
        
        return result.empty() ? "0" : result;
    }
};

int main() {
    Solution sol;
    string num = "1432219";
    int k = 3;

    cout << "Original Number: " << num << endl;
    cout << "After Removing " << k << " Digits: " << sol.removeKdigits(num, k) << endl; // Output: "1219"

    return 0;
}