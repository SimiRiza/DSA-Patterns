/*
 * Problem:
 * LeetCode 82 - Remove Duplicates from Sorted List II
 *
 * Approach:
 * - Traverse the sorted list using curr.
 * - Skip all consecutive duplicates using rep.
 * - Use a dummy node so deleting the head is handled like any other node.
 * - Link prev to the first non-duplicate node when duplicates are found.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Self Notes/Improvements:
 * - A dummy node simplifies the logic by eliminating the need for a special case when the head is part of a duplicate sequence.
     avoids a separate head-deletion case (if(head == curr)).

 * - Instead of using a boolean flag to track duplicates, simply check 
     if rep has moved from curr->next; if it has, duplicates were found.
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

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;

        ListNode *curr = head, *rep = nullptr;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy;

        while(curr){
            rep = curr->next;

            while(rep && rep->val == curr->val){
                rep = rep->next;
            }

            if(rep != curr->next){
                prev->next = rep;
                curr = rep;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};

// Helper to print linked list
void printList(ListNode* head) {
    while(head) {
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Test: 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    Solution sol;

    cout << "Original: ";
    printList(head);

    head = sol.deleteDuplicates(head);

    cout << "Result:   ";
    printList(head);

    return 0;
}