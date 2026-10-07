#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int papersCount = n - mid; // Number of papers with citations >= citations[mid]
            
            if (citations[mid] == papersCount) {
                return papersCount;
            } else if (citations[mid] < papersCount) {
                low = mid + 1; // Need larger citation values
            } else {
                high = mid - 1; // Need smaller citation values / more papers
            }
        }
        
        return n - low;
    }
};

int main() {
    Solution sol;
    vector<int> citations1 = {0, 1, 3, 5, 6};
    vector<int> citations2 = {1, 2, 100};

    cout << "H-Index (Example 1): " << sol.hIndex(citations1) << endl; // Output: 3
    cout << "H-Index (Example 2): " << sol.hIndex(citations2) << endl; // Output: 2

    return 0;
}