#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getNext(vector<int>& nums, int i, bool isForward) {
        bool currentDirection = nums[i] >= 0;
        // Direction mismatch invalidates the loop segment
        if (isForward != currentDirection) return -1;

        int n = nums.size();
        int nextIndex = ((i + nums[i]) % n + n) % n;

        // Self-loop invalidates the cycle (k <= 1)
        if (nextIndex == i) return -1;

        return nextIndex;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            // Skip elements already visited/marked as non-cycling
            if (nums[i] == 0) continue;

            int slow = i;
            int fast = i;
            bool isForward = nums[i] >= 0;

            while (true) {
                slow = getNext(nums, slow, isForward);
                fast = getNext(nums, fast, isForward);
                if (fast != -1) {
                    fast = getNext(nums, fast, isForward);
                }

                if (slow == -1 || fast == -1) break;

                if (slow == fast) return true;
            }

            // Mark visited path with 0 for O(N) time and O(1) space
            int current = i;
            while (nums[current] != 0 && (nums[current] >= 0) == isForward) {
                int next = ((current + nums[current]) % n + n) % n;
                nums[current] = 0;
                current = next;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, -1, 1, 2, 2};

    cout << "Contains Circular Loop: " << (sol.circularArrayLoop(nums) ? "True" : "False") << endl; // Output: True

    return 0;
}