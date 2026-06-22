/*
Approach:
When a pointer reaches null,
redirect it to the head of the other list.

Both pointers travel equal total distance,
so they meet at the intersection or null.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* a = headA;
        ListNode* b = headB;

        while (a != b) {
            // If end reached, start traversing other list
            a = (a == nullptr) ? headB : a->next;
            b = (b == nullptr) ? headA : b->next;
        }

        // Either intersection node or nullptr
        return a;
    }
};

int main() {
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(7);
    headA->next->next = common;

    ListNode* headB = new ListNode(99);
    headB->next = common;

    Solution obj;
    ListNode* ans = obj.getIntersectionNode(headA, headB);

    if (ans)
        cout << "Intersection: " << ans->val << '\n';
    else
        cout << "No Intersection\n";

    return 0;
}