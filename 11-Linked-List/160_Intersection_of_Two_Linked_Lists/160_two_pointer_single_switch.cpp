/*
Approach:
Each pointer is allowed to switch lists only once.

If a pointer becomes null for the second time,
there is no intersection.

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

        bool switched_a = false;
        bool switched_b = false;

        while (true) {
            // Found intersection
            if (a == b)
                return a;

            if (a == nullptr) {
                // Already switched once -> no intersection
                if (switched_a)
                    return nullptr;

                switched_a = true;
                a = headB;
            } else {
                a = a->next;
            }

            if (b == nullptr) {
                // Already switched once -> no intersection
                if (switched_b)
                    return nullptr;

                switched_b = true;
                b = headA;
            } else {
                b = b->next;
            }
        }
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