/*
Approach:
Use a dummy node and a tail pointer.
Compare nodes from both sorted lists and attach the smaller node directly
to the merged list. Reuse existing nodes instead of creating new ones.
Finally, attach the remaining nodes.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 != nullptr) return list2;
        if(list2 == nullptr && list1 != nullptr) return list1;

        ListNode *curr1 = list1, *curr2 = list2;
        ListNode *head = new ListNode(-1);
        ListNode *tail = head;

        while(curr1 != nullptr && curr2 != nullptr) {

            if(curr1->val <= curr2->val) {
                tail->next = curr1;
                tail = curr1;
                curr1 = curr1->next;
            }
            else {
                tail->next = curr2;
                tail = curr2;
                curr2 = curr2->next;
            }
        }

        if(curr2) tail->next = curr2;
        if(curr1) tail->next = curr1;

        return head->next;
    }
};

void printList(ListNode* head) {
    while(head) {
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution obj;
    ListNode* ans = obj.mergeTwoLists(list1, list2);

    printList(ans);

    return 0;
}