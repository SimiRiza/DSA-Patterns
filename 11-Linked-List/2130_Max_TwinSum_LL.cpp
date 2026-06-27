#include <iostream>
#include <algorithm>
using namespace std;

/*
 * Problem:
 * LeetCode 2130 - Maximum Twin Sum of a Linked List
 *
 * Intuition:
 * Reversing the second half allows each node to line up with its twin,
 * making it easy to calculate twin sums in a single traversal.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Self Note:
 * Reverse the second half whenever you need to compare symmetric nodes
 * in a linked list while keeping extra space constant.
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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow->next;
        slow->next = nullptr;

        ListNode *prev = nullptr, *NN = nullptr;

        while (curr) {
            NN = curr->next;
            curr->next = prev;
            prev = curr;
            curr = NN;
        }

        slow = head;
        int max_sum = 0;

        while (prev && slow) {
            max_sum = max(max_sum, prev->val + slow->val);
            prev = prev->next;
            slow = slow->next;
        }

        return max_sum;
    }
};

int main() {
    // Test Case: [5,4,2,1]
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution obj;
    cout << "Maximum Twin Sum: " << obj.pairSum(head) << endl;

    // Expected Output:
    // Maximum Twin Sum: 6

    return 0;
}