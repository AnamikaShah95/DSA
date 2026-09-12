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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* next_node = curr->next; // Store the next node
            curr->next = prev;                // Reverse the pointer
            prev = curr;                      // Move prev forward
            curr = next_node;                 // Move curr forward
        }
        
        return prev; // prev is now the new head
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

    ListNode* reversedHead = sol.reverseList(head);
    cout << "Reversed List: ";
    printList(reversedHead); // Output: 5 -> 4 -> 3 -> 2 -> 1

    return 0;
}