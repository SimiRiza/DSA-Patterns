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
 * Problem: LeetCode 2095 - Delete the Middle Node of a Linked List
 
 * Approach:
 * - Handle lists with 1 and 2 nodes as special cases.
 * - Use slow and fast pointers to locate the node before the middle.
 * - Skip the middle node by updating the next pointer.

 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *

 */

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head;

        if (!head->next)
            return nullptr;

        if (!head->next->next) {
            head->next = nullptr;
            return head;
        }

        ListNode* fast = head->next->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};

int main() {
    // Test Case:
    // 1 -> 3 -> 4 -> 7 -> 1 -> 2 -> 6
    // Expected Output:
    // 1 3 4 1 2 6

    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(6);

    Solution sol;
    head = sol.deleteMiddle(head);

    while (head) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}