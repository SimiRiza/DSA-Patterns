/*
Approach:
- Traverse the linked list.
- Store each node address in an unordered_set.
- If a node address is seen again, a cycle exists.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <unordered_set>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *curr = head;
        unordered_set<ListNode*> prev_vals;

        while(curr != nullptr && curr->next != nullptr) {
            if(prev_vals.count(curr)) {
                return true;
            }

            prev_vals.insert(curr);
            curr = curr->next;
        }

        return false;
    }
};

/*
Simple Test Driver
*/

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