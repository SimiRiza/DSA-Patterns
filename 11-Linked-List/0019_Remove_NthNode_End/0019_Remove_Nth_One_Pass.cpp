/*
Approach:
- Move fast pointer n steps ahead.
- If fast becomes nullptr, remove head.
- Move slow and fast together until fast reaches last node.
- Slow will be at node before target, delete target.

Time Complexity: O(N)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        // move fast n steps ahead
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // remove head
        if(fast == nullptr)
            return head->next;

        while(fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // delete target node
        slow->next = slow->next->next;

        return head;
    }
};

void printList(ListNode* head) {
    while(head) {
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    head = sol.removeNthFromEnd(head, 2);

    printList(head);

    return 0;
}