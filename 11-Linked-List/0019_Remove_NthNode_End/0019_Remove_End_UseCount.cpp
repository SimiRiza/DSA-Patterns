#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
Approach:
1. Count the total number of nodes in the linked list.
2. Find the position of the node to remove from the beginning.
3. If removing the head, return head->next.
4. Otherwise, move to the node just before the target node and skip it.

Time Complexity: O(N)
Space Complexity: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* curr = head;

        while(curr){
            count++;
            curr = curr->next;
        }

        int pos = count - n;

        if(pos == 0)
            return head->next;

        curr = head;
        for(int i = 1; i < pos; i++)
            curr = curr->next;

        curr->next = curr->next->next;

        return head;
    }
};

void printList(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    head = obj.removeNthFromEnd(head, 2);

    printList(head); // 1 2 3 5

    return 0;
}