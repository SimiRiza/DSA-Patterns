/*
Approach:
- Use fast/slow pointers to reach the middle and derive the total length.
- Compute the position of the node before the target from the front.
- If the position is before the middle, restart from head.
- Otherwise continue from the middle and delete the node.

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
        int count = 1;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next != nullptr) {
            count++;
            slow = slow->next;
            fast = fast->next->next;
        }

        int num_ele;
        if (fast == nullptr) // even length
            num_ele = count * 2 - 2;
        else                 // odd length
            num_ele = count * 2 - 1;

        // position of node before target from front
        int pos = num_ele - n;

        // remove head
        if (pos == 0) {
            return head->next;
        }

        // target lies before middle
        if (pos < count) {
            slow = head;
            count = 1;
        }

        while (slow && count != pos) {
            count++;
            slow = slow->next;
        }

        // delete target node
        if (slow && slow->next) {
            slow->next = slow->next->next;
        }

        return head;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
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