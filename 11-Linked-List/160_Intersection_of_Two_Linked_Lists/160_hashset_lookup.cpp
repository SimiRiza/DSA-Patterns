/*
Approach:
Store all nodes of List A in a hash set.
Traverse List B and return the first common node.

Time Complexity: O(n + m)
Space Complexity: O(n)
*/

#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> seen;

        // Store all nodes of List A
        ListNode* a = headA;
        while (a) {
            seen.insert(a);
            a = a->next;
        }

        // First node of List B already present in set is intersection
        ListNode* b = headB;
        while (b) {
            if (seen.count(b))
                return b;

            b = b->next;
        }

        return nullptr;
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