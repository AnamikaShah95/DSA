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
    ListNode* swapPairs(ListNode* head) {
        // Dummy node acts as a prev pointer before the current head
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        
        while (prev->next != nullptr && prev->next->next != nullptr) {
            // Nodes to be swapped
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            
            // Reassign pointers to swap nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;
            
            // Advance prev two steps forward for the next pair
            prev = first;
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
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));

    cout << "Original List: ";
    printList(head);

    ListNode* swappedHead = sol.swapPairs(head);
    cout << "Swapped List: ";
    printList(swappedHead); // Output: 2 -> 1 -> 4 -> 3

    return 0;
}