#include <iostream>

using namespace std;

class Solution {
private:
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int digit = n % 10;
            totalSum += digit * digit;
            n /= 10;
        }
        return totalSum;
    }

public:
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);

        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        return fast == 1;
    }
};

int main() {
    Solution sol;
    int n1 = 19, n2 = 2;

    cout << n1 << " is happy? " << (sol.isHappy(n1) ? "True" : "False") << endl; // Output: True
    cout << n2 << " is happy? " << (sol.isHappy(n2) ? "True" : "False") << endl; // Output: False

    return 0;
}