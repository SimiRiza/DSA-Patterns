// Filename: RemoveCycleLinkedList.cpp
// Approach: Floyd's Cycle Detection + Remove Cycle
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    void removeCycle(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        bool hasCycle = false;

        // Detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }

        if (!hasCycle) return;

        // Find cycle start
        slow = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* cycleStart = slow;

        // Find node just before cycle start
        ListNode* temp = cycleStart;

        while (temp->next != cycleStart) {
            temp = temp->next;
        }

        // Remove cycle
        temp->next = nullptr;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create cycle: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    Solution obj;
    obj.removeCycle(head);

    cout << "Linked List after removing cycle:\n";
    printList(head);

    return 0;
}