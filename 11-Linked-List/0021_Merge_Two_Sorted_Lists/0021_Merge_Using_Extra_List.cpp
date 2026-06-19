/*
Approach:
Use a dummy node and tail pointer to build the merged sorted list.
Compare nodes from both lists, create a new node with the smaller value,
attach it to the merged list, and move forward.
Finally, attach the remaining nodes from the non-empty list.

Time Complexity: O(n + m)
Space Complexity: O(n + m)
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
                ListNode *NN = new ListNode(curr1->val);
                curr1 = curr1->next;
                tail->next = NN;
                tail = NN;
            }
            else {
                ListNode *NN = new ListNode(curr2->val);
                curr2 = curr2->next;
                tail->next = NN;
                tail = NN;
            }
        }

        // remaining
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