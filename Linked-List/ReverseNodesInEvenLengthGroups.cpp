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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* prevGroupEnd = head;
        int targetLen = 2; // Group 1 (length 1) never reverses, start from group 2
        
        while (prevGroupEnd && prevGroupEnd->next) {
            // Step 1: Count actual nodes available in current group
            ListNode* curr = prevGroupEnd->next;
            int count = 0;
            while (curr && count < targetLen) {
                curr = curr->next;
                count++;
            }
            
            // Step 2: Reverse if the ACTUAL group length is even
            if (count % 2 == 0) {
                ListNode* currNode = prevGroupEnd->next;
                ListNode* prev = curr; // Points to the node after the current group
                ListNode* groupStart = currNode;
                
                for (int i = 0; i < count; i++) {
                    ListNode* nextNode = currNode->next;
                    currNode->next = prev;
                    prev = currNode;
                    currNode = nextNode;
                }
                
                prevGroupEnd->next = prev;
                prevGroupEnd = groupStart;
            } else {
                // If odd, skip past these nodes
                for (int i = 0; i < count; i++) {
                    prevGroupEnd = prevGroupEnd->next;
                }
            }
            
            targetLen++;
        }
        
        return head;
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
    // List: 5 -> 2 -> 6 -> 3 -> 9 -> 1 -> 7 -> 3 -> 8 -> 4
    ListNode* head = new ListNode(5, new ListNode(2, new ListNode(6, new ListNode(3, 
                     new ListNode(9, new ListNode(1, new ListNode(7, new ListNode(3, 
                     new ListNode(8, new ListNode(4))))))))));

    cout << "Original List: ";
    printList(head);

    ListNode* result = sol.reverseEvenLengthGroups(head);
    cout << "Reversed Even Groups: ";
    printList(result); // Output: 5 -> 6 -> 2 -> 3 -> 9 -> 1 -> 4 -> 8 -> 3 -> 7

    return 0;
}