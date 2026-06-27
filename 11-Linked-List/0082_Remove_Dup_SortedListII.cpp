/*
 * Problem:
 * LeetCode 82 - Remove Duplicates from Sorted List II
 *
 * Approach:
 * 1. Traverse the sorted linked list.
 * 2. For each node, check if it has duplicate values ahead.
 * 3. If duplicates exist, skip the entire duplicate sequence.
 * 4. Otherwise, keep the node and move forward.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;

        ListNode *curr = head, *rep = nullptr, *prev = nullptr;

        while (curr) {
            rep = curr->next;
            bool isDup = false;

            // Move rep to the first node having a different value
            while (rep && rep->val == curr->val) {
                rep = rep->next;
                isDup = true;
            }

            if (isDup) {
                // Duplicate block starts from the head
                if (head == curr) {
                    curr = rep;
                    head = rep;
                } else {
                    // Skip the entire duplicate block
                    prev->next = rep;
                    curr = rep;
                }
            } else {
                // Current node is unique, so keep it
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
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
    // Test Case: [1,2,3,3,4,4,5]
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    Solution obj;
    head = obj.deleteDuplicates(head);

    cout << "Updated List: ";
    printList(head);

    // Expected Output:
    // Updated List: 1 -> 2 -> 5

    return 0;
}