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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Step 1: Reach the node prior to the 'left' boundary
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        // Step 2: In-place sublist reversal using head insertion
        ListNode* curr = prev->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode* then = curr->next;
            curr->next = then->next;
            then->next = prev->next;
            prev->next = then;
        }

        return dummy.next;
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

    ListNode* modifiedHead = sol.reverseBetween(head, 2, 4);
    cout << "Sublist Reversed (2 to 4): ";
    printList(modifiedHead); // Output: 1 -> 4 -> 3 -> 2 -> 5

    return 0;
}