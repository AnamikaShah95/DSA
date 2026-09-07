#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        // Compute prefix sums (using long long to prevent integer overflow)
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        deque<int> dq;
        int minLen = n + 1;

        for (int j = 0; j <= n; ++j) {
            // Check if current prefix sum forms a valid subarray >= k with the front of deque
            while (!dq.empty() && prefix[j] - prefix[dq.front()] >= k) {
                minLen = min(minLen, j - dq.front());
                dq.pop_front();
            }

            // Maintain monotonic increasing order in deque
            while (!dq.empty() && prefix[j] <= prefix[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(j);
        }

        return minLen <= n ? minLen : -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, -1, 2};
    int k = 3;

    cout << "Shortest Subarray Length: " << sol.shortestSubarray(nums, k) << endl; // Output: 3

    return 0;
}