#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/**
 * LeetCode 143 - Reorder List
 *
 * Approach:
 * 1. Find the middle of the linked list using slow & fast pointers.
 * 2. Split the list into two halves.
 * 3. Reverse the second half.
 * 4. Merge the two halves alternately.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Step 1: Find the middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Split the list
        ListNode* curr = slow->next;
        slow->next = nullptr;

        // Step 3: Reverse the second half
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 4: Merge the two halves
        ListNode* l1 = head;
        ListNode* l2 = prev;

        while (l1 && l2) {
            ListNode* next1 = l1->next;
            ListNode* next2 = l2->next;

            l1->next = l2;
            if (next1)
                l2->next = next1;

            l1 = next1;
            l2 = next2;
        }
    }
};

int main() {
    // Create: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    obj.reorderList(head);

    // Print reordered list
    cout << "Reordered List: ";
    ListNode* temp = head;
    while (temp) {
        cout << temp->val;
        if (temp->next)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;

    // Free memory
    temp = head;
    while (temp) {
        ListNode* next = temp->next;
        delete temp;
        temp = next;
    }

    return 0;
}