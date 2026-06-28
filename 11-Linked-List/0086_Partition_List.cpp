/*
 * Problem:
 * LeetCode 86 - Partition List
 *
 * Approach:
 * 1. Create two separate lists:
 *    - One for nodes with values less than x.
 *    - One for nodes with values greater than or equal to x.
 * 2. Traverse the original list and append each node to its respective list.
 * 3. Connect the low-value list with the high-value list.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l_ptr = new ListNode(-1);
        ListNode* low_head = l_ptr;

        ListNode* h_ptr = new ListNode(-1);
        ListNode* high_head = h_ptr;

        ListNode* curr = head;

        while (curr) {
            if (curr->val < x) {
                l_ptr->next = curr;      // Append to the "less than x" list
                l_ptr = l_ptr->next;
                curr = curr->next;
            } else {
                h_ptr->next = curr;      // Append to the "greater/equal x" list
                h_ptr = h_ptr->next;
                curr = curr->next;
            }
        }

        h_ptr->next = nullptr;           // Prevent cycles from original links
        l_ptr->next = high_head->next;   // Join both partitions

        return low_head->next;
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
    // Test Case: [1,4,3,2,5,2], x = 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    Solution obj;
    head = obj.partition(head, 3);

    cout << "Partitioned List: ";
    printList(head);

    // Expected Output:
    // Partitioned List: 1 -> 2 -> 2 -> 4 -> 3 -> 5

    return 0;
}