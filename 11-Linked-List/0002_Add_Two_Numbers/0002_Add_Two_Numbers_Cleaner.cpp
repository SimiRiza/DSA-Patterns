/*
Approach:
- Traverse both linked lists simultaneously.
- Add corresponding digits along with carry.
- Create a new node with (sum % 10).
- Update carry as (sum / 10).
- Continue until both lists and carry are exhausted.

Time Complexity: O(max(N, M))
Space Complexity: O(max(N, M))   // Output list
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *curr1 = l1, *curr2 = l2;
        int sum = 0, carry = 0;

        ListNode *head = new ListNode(0);
        ListNode *tail = head;

        while(curr1 || curr2 || carry){
            if(curr1){
                sum = curr1->val;
                curr1 = curr1->next;
            }

            if(curr2){
                sum += curr2->val;
                curr2 = curr2->next;
            }

            sum += carry;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            carry = sum / 10;
            sum = 0;
        }

        return head->next;
    }
};

void printList(ListNode* head){
    while(head){
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // 342 + 465 = 807
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution obj;
    ListNode* result = obj.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}