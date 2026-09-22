#include <iostream>
#include <vector>

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
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode*> stack;
        ListNode* curr = head;

        while (curr) {
            while (!stack.empty() && stack.back()->val < curr->val) {
                stack.pop_back();
            }
            stack.push_back(curr);
            curr = curr->next;
        }

        // Re-link the remaining nodes
        for (int i = 0; i < (int)stack.size() - 1; ++i) {
            stack[i]->next = stack[i + 1];
        }
        stack.back()->next = nullptr;

        return stack[0];
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
    ListNode* head = new ListNode(5, new ListNode(2, new ListNode(13, new ListNode(3, new ListNode(8)))));

    cout << "Original List: ";
    printList(head);

    ListNode* result = sol.removeNodes(head);
    cout << "Filtered List: ";
    printList(result); // Output: 13 -> 8

    return 0;
}