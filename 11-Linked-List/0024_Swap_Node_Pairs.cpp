/*
 * Problem:
 * LeetCode 24 - Swap Nodes in Pairs
 *
 * Approach:
 * 1. Handle edge cases for empty and single-node lists.
 * 2. Store the second node as the new head.
 * 3. Traverse the list two nodes at a time.
 * 4. Swap each adjacent pair by updating pointers.
 * 5. Connect the swapped pair to the next pair.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Self Note:
 * Self Note: Reset temporary pointers each iteration.
   Stale pointers can accidentally create loops (e.g old f2 value).
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* b1 = head;

        if (!head) return nullptr;
        if (!head->next) return head;

        ListNode* newHead = head->next;
        ListNode *b2, *f1, *f2 = nullptr;

        while (b1 && b1->next) {
            b2 = b1->next;
            f1 = b2->next;

            if (f1)
                f2 = f1->next;
            else
                f2 = nullptr;

            b2->next = b1;

            if (f2)
                b1->next = f2;
            else
                b1->next = f1;

            b1 = f1;
        }

        return newHead;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Test Case: [1,2,3,4]
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution obj;
    head = obj.swapPairs(head);

    cout << "Swapped List: ";
    printList(head);

    // Expected Output:
    // Swapped List: 2 -> 1 -> 4 -> 3

    return 0;
}