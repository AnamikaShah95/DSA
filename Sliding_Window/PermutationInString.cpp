#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        if (n1 > n2) return false;
        
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        
        // Populate frequency tables for s1 and initial s2 window
        for (int i = 0; i < n1; ++i) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        
        if (count1 == count2) return true;
        
        // Slide the fixed-size window over s2
        for (int i = n1; i < n2; ++i) {
            count2[s2[i] - 'a']++;       // Include incoming char
            count2[s2[i - n1] - 'a']--;  // Evict outgoing char
            
            if (count1 == count2) return true;
        }
        
        return false;
    }
};

int main() {
    Solution sol;
    string s1 = "ab", s2 = "eidbaooo";

    cout << "Contains Permutation: " << (sol.checkInclusion(s1, s2) ? "True" : "False") << endl; // Output: True

    return 0;
}