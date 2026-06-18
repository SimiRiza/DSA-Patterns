/*
Approach:
1. Reach the node just before position 'left'.
2. Reverse nodes from left to right.
3. Reconnect:
   - node before left -> new head of reversed part
   - old left node -> node after right

Time Complexity: O(n)
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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (left == right) return head; // nothing to reverse

        ListNode* curr = head;
        ListNode* leftNode = nullptr;
        ListNode* rytNode = nullptr;
        ListNode* bef_left = nullptr;
        ListNode* aft_ryt = nullptr;

        int count = 1;

        // move to node before left
        while (count < left - 1) {
            curr = curr->next;
            count++;
        }

        if (left != 1) {
            bef_left = curr;
            curr = curr->next;
            count++;
            leftNode = curr;
        }
        else {
            leftNode = curr; // leftNode was nullptr earlier
        }

        ListNode* prev = bef_left;
        ListNode* nextNode = nullptr;

        while (count <= right) {

            if (count == right)
                rytNode = curr; // will become new head of reversed part

            nextNode = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextNode;

            count++;
        }

        aft_ryt = curr; // curr already points to node after right

        leftNode->next = aft_ryt; // old left becomes tail after reversal

        if (bef_left != nullptr)
            bef_left->next = rytNode; // reconnect left part
        else
            head = rytNode; // reversal started from head

        return head;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << '\n';
}

int main() {
    ListNode* head = new ListNode(
        1,
        new ListNode(
            2,
            new ListNode(
                3,
                new ListNode(
                    4,
                    new ListNode(5)
                )
            )
        )
    );

    Solution obj;

    cout << "Original: ";
    printList(head);

    head = obj.reverseBetween(head, 2, 4);

    cout << "After Reverse [2,4]: ";
    printList(head);

    return 0;
}