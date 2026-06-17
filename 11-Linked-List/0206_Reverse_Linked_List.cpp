#include <iostream>
using namespace std;

/**
 * LeetCode 206 - Reverse Linked List
 *
 * Approach:
 * Traverse the linked list and reverse each link one by one.
 * Use three pointers: curr, prev, and nextnode to keep track of 
   the current node, previous node, and next node.
 * Time Complexity: O(n)
 * Space Complexity: O(1)
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
    ListNode* reverseList(ListNode* head) {

        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nextnode;

        while(curr != nullptr){

            nextnode = curr->next;  // Save next node

            curr->next = prev;      // Reverse current link

            prev = curr;            // Move prev forward
            curr = nextnode;        // Move curr forward
        }

        return prev;
    }
};

/*
Self Note:
Save next node before reversing the link, a temp pointer isnt needed
otherwise the remaining list is lost.
*/

int main() {

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    ListNode* result = obj.reverseList(head);

    cout << "Reversed List: ";

    while(result != nullptr){
        cout << result->val << " ";
        result = result->next;
    }

    cout << endl;

    return 0;
}