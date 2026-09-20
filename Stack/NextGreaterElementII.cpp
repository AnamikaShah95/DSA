#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st; // Stores indices

        for (int i = 0; i < 2 * n; ++i) {
            int num = nums[i % n];
            while (!st.empty() && nums[st.top()] < num) {
                result[st.top()] = num;
                st.pop();
            }
            if (i < n) {
                st.push(i);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};

    vector<int> res = sol.nextGreaterElements(nums);

    cout << "Next Greater Elements: [";
    for (size_t i = 0; i < res.size(); ++i) {
        cout << res[i] << (i + 1 < res.size() ? ", " : "");
    }
    cout << "]" << endl; // Output: [2, -1, 2]

    return 0;
}