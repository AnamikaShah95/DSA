#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> count;
        
        // Count frequency of each character in text
        for (char c : text) {
            count[c]++;
        }
        
        // Return the minimum possible count based on requirements
        return min({
            count['b'],
            count['a'],
            count['l'] / 2,
            count['o'] / 2,
            count['n']
        });
    }
};

int main() {
    Solution sol;
    string text1 = "nlaebolko";
    string text2 = "loonbalxballpoon";

    cout << "Input: \"" << text1 << "\" -> Max Balloons: " << sol.maxNumberOfBalloons(text1) << endl; // Output: 1
    cout << "Input: \"" << text2 << "\" -> Max Balloons: " << sol.maxNumberOfBalloons(text2) << endl; // Output: 2

    return 0;
}