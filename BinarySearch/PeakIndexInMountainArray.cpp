#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] < arr[mid + 1]) {
                // Peak lies on the right side
                left = mid + 1;
            } else {
                // Peak lies on the left side or at mid
                right = mid;
            }
        }

        return left;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {0, 1, 0};
    vector<int> arr2 = {0, 2, 1, 0};
    vector<int> arr3 = {0, 10, 5, 2};

    cout << "Peak Index: " << sol.peakIndexInMountainArray(arr1) << endl; // Output: 1
    cout << "Peak Index: " << sol.peakIndexInMountainArray(arr2) << endl; // Output: 1
    cout << "Peak Index: " << sol.peakIndexInMountainArray(arr3) << endl; // Output: 1

    return 0;
}