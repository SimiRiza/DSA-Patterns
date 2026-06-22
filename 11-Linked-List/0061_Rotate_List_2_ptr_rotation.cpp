/*
Approach:
1. Find length of list.
2. Reduce k using k % length.
3. Move fast pointer k nodes ahead.
4. Move slow and fast together until fast reaches last node.
5. Break list at slow and attach tail to old head.

Time Complexity: O(n)
Space Complexity: O(1)

Self Notes:
- For circular rotations, always do k %= n first.
- If k == 0 after modulo, return head immediately.
*/

#include <iostream>
using namespace std;

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
        ListNode* slow = head;
        ListNode* fast = head;

        int n = 0;

        // Find length of linked list
        while (slow) {
            n++;
            slow = slow->next;
        }

        if (n == 0)
            return nullptr;

        slow = head;

        // Remove unnecessary full rotations
        k = k % n;

        if (k == 0)
            return head;

        // Move fast pointer k nodes ahead
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }

        // Maintain gap of k nodes
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // Make list temporarily circular
        fast->next = head;

        // New head is next of slow
        head = slow->next;

        // Break circle
        slow->next = nullptr;

        return head;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << '\n';
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution obj;
    head = obj.rotateRight(head, k);

    printList(head);

    return 0;
}