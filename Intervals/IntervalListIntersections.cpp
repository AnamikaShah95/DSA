#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int i = 0, j = 0;
        
        while (i < firstList.size() && j < secondList.size()) {
            // Overlap starting point is the maximum of starts
            int start = max(firstList[i][0], secondList[j][0]);
            // Overlap ending point is the minimum of ends
            int end = min(firstList[i][1], secondList[j][1]);
            
            // Valid intersection check
            if (start <= end) {
                result.push_back({start, end});
            }
            
            // Increment pointer for interval ending first
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> firstList = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
    vector<vector<int>> secondList = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};

    vector<vector<int>> result = sol.intervalIntersection(firstList, secondList);
    cout << "Interval Intersections:\n";
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl; // Output: [1, 2] [5, 5] [8, 10] [15, 23] [24, 24] [25, 25]

    return 0;
}