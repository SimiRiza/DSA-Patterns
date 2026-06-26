/**
 * Approach: Floyd's Cycle Detection (Tortoise and Hare)
 *
 * Algorithm:
 * 1. Initialize slow and fast pointers at the head.
 * 2. Move slow by one step and fast by two steps.
 * 3. If they meet, a cycle exists.
 * 4. Reset slow to head.
 * 5. Move both pointers one step until they meet again.
 * 6. Return the meeting node.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                break;
        }

        if (!fast || !fast->next)
            return nullptr;

        slow = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

int main() {

    // Create linked list:
    // 3 -> 2 -> 0 -> -4
    //      ^         |
    //      |_________|

    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;   // Cycle starts at node with value 2

    Solution obj;

    ListNode* ans = obj.detectCycle(head);

    if (ans)
        cout << "Cycle starts at node: " << ans->val << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}