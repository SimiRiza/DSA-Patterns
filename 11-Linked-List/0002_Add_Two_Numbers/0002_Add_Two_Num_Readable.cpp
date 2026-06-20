/*
Approach:
- Traverse both linked lists simultaneously.
- Add corresponding digits along with carry.
- Create new nodes for the resulting digits.
- Handle any remaining nodes and final carry.

Time Complexity: O(max(m, n))
Space Complexity: O(max(m, n))   // output list
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
        int sum = 0, carry = 0, value = 0;

        ListNode *head = new ListNode(0);
        ListNode *tail = head;

        while(curr1 != nullptr && curr2 != nullptr){
            sum = carry + curr1->val + curr2->val;
            value = sum % 10;
            carry = sum / 10;

            tail->next = new ListNode(value);
            tail = tail->next;

            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        while(curr1 != nullptr){
            sum = carry + curr1->val;
            value = sum % 10;
            carry = sum / 10;

            tail->next = new ListNode(value);
            tail = tail->next;

            curr1 = curr1->next;
        }

        while(curr2 != nullptr){
            sum = carry + curr2->val;
            value = sum % 10;
            carry = sum / 10;

            tail->next = new ListNode(value);
            tail = tail->next;

            curr2 = curr2->next;
        }

        if(carry != 0){
            tail->next = new ListNode(carry);
        }

        return head->next;
    }
};

/*
Self Notes:
- Used a dummy head node to simplify linked list construction.
- Important edge case: append the final carry if it exists.
- This solution is optimal in time and space complexity.
- It can be written in a cleaner way using a single loop:
      while(curr1 || curr2 || carry)
  which removes duplicated logic from the three loops.
*/

void printList(ListNode* head){
    while(head){
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution obj;
    ListNode* ans = obj.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(ans);

    return 0;
}