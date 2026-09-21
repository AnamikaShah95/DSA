#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st; // Stores indices of temperatures in decreasing order

        for (int i = 0; i < n; ++i) {
            // Pop elements from the stack while the current temperature 
            // is warmer than the temperature at the index on top of the stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                answer[prevIndex] = i - prevIndex;
            }
            // Push current index onto stack
            st.push(i);
        }

        return answer;
    }
};

int main() {
    Solution sol;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> res = sol.dailyTemperatures(temperatures);

    cout << "Days to Wait: [";
    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i] << (i + 1 < res.size() ? ", " : "");
    }
    cout << "]" << endl; // Output: [1, 1, 4, 2, 1, 1, 0, 0]

    return 0;
}