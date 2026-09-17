#include <iostream>

using namespace std;

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find length and original tail
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // Step 2: Handle cases where k >= length
        k = k % length;
        if (k == 0) return head;

        // Step 3: Make it a circular list
        tail->next = head;

        // Step 4: Find new tail: (length - k - 1) steps from head
        ListNode* new_tail = head;
        for (int i = 0; i < length - k - 1; i++) {
            new_tail = new_tail->next;
        }

        // Step 5: Set new head and break the ring
        ListNode* new_head = new_tail->next;
        new_tail->next = nullptr;

        return new_head;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    cout << "Original List: ";
    printList(head);

    ListNode* rotatedHead = sol.rotateRight(head, 2);
    cout << "Rotated List (k=2): ";
    printList(rotatedHead); // Output: 4 -> 5 -> 1 -> 2 -> 3

    return 0;
}