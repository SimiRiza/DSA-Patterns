/*
 * Problem:
 * LeetCode 328 - Odd Even Linked List
 *
 * Approach:
 * 1. Maintain two pointers: one for odd-indexed nodes and one for even-indexed nodes.
 * 2. Keep the head of the even list separately.
 * 3. Rearrange the next pointers so all odd nodes come first, followed by all even nodes.
 * 4. Connect the odd list to the even list.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = head;
        if (!head) return nullptr;

        ListNode* even = head->next;
        ListNode* evenhead = head->next;
        if (!even) return head;

        while (odd && odd->next && even && even->next) {
            if (odd->next->next)
                odd->next = odd->next->next;

            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }

        if (even)
            even->next = nullptr;

        odd->next = evenhead;
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
    // Test Case: [1,2,3,4,5]
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    head = obj.oddEvenList(head);

    cout << "Reordered List: ";
    printList(head);

    // Expected Output:
    // Reordered List: 1 -> 3 -> 5 -> 2 -> 4

    return 0;
}