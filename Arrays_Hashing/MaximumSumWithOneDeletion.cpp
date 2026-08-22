#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& a) {
        int n = a.size();
        int noDel = a[0];
        int oneDel = INT_MIN;
        int res = a[0];

        for (int i = 1; i < n; i++) {
            int prevNoDel = noDel;

            noDel = max(a[i], noDel + a[i]);

            // Delete current element OR keep current element with an earlier deletion
            oneDel = max(prevNoDel, (oneDel == INT_MIN) ? INT_MIN : oneDel + a[i]);

            res = max({res, noDel, oneDel});
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1, -2, 0, 3};

    cout << "Max Sum with One Deletion: " << sol.maximumSum(a) << endl; // Output: 4 (delete -2 -> [1, 0, 3])

    return 0;
}