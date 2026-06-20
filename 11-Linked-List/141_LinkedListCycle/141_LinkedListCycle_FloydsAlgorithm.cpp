/*
Approach:
- Use Floyd's Cycle Detection Algorithm (Tortoise and Hare).
- slow moves 1 step, fast moves 2 steps.
- If a cycle exists, they will eventually meet.
- If fast reaches nullptr, there is no cycle.

Time Complexity: O(n)
Space Complexity: O(1)
*/

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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                return true;
            }
        }

        return false;
    }
};

/*
Simple Test Driver
*/

#include <iostream>
using namespace std;

int main() {
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; // cycle

    Solution obj;
    cout << obj.hasCycle(n1) << endl; // 1

    return 0;
}