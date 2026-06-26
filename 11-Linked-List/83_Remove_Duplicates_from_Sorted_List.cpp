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

/**
 * Intuition:
 * - Since the list is sorted, duplicates are adjacent.
 * - Removing a duplicate is simply changing one pointer; no extra space is needed.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Self Note:
 * - O(n) despite nested while loops because each node is visited or removed only once.
 * - The inner loop never revisits nodes; skipped nodes are gone forever.
 * -----------------------------------------
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr && curr->next) {
            while (curr && curr->next && curr->next->val == curr->val) {
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }

        return head;
    }
};

int main() {
    // 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    Solution sol;
    head = sol.deleteDuplicates(head);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }

    // Expected Output:
    // 1 2 3

    return 0;
}