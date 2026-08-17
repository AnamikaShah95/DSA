#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        // Step 1: Detect if a cycle exists
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            // Cycle detected
            if (slow == fast) {
                // Step 2: Find the entry point of the cycle
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        
        return nullptr; // No cycle found
    }
};

int main() {
    // 3 -> 2 -> 0 -> -4
    //      ^          |
    //      |__________|
    ListNode *head = new ListNode(3);
    ListNode *cycleNode = new ListNode(2);
    head->next = cycleNode;
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = cycleNode; // Creates cycle at value 2

    Solution sol;
    ListNode *entry = sol.detectCycle(head);
    
    if (entry != nullptr) {
        cout << "Cycle starts at node with value: " << entry->val << endl; // Output: 2
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}