/*
Approach:
Copy the value of the next node into the current node,
then bypass the next node.

Time Complexity: O(1)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
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
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    Solution obj;

    obj.deleteNode(head->next); // delete node with value 5

    printList(head);

    return 0;
}

/*
Self Notes:

1. We are NOT given the head of the linked list.
2. We cannot actually remove the current node.
3. Copy next node's value into current node.
4. Skip the next node using:
   node->next = node->next->next;
5. Works because the node to delete is guaranteed
   not to be the last node.
*/