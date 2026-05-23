/*
 * LeetCode 155 - Min Stack
 * Approach: Two Stack Approach
 *
 * Description:
 * - st1 stores all inserted elements normally.
 * - st2 stores the minimum history.
 * - Whenever a value <= current minimum is pushed,
 *   also push it into st2.
 * - During pop, if the popped element equals the
 *   current minimum, remove it from st2 as well.
 *
 * Time Complexity:
 * - push()   : O(1)
 * - pop()    : O(1)
 * - top()    : O(1)
 * - getMin() : O(1)
 *
 * Space Complexity:
 * - O(n)
 */

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    // Stack for storing all elements
    stack<int> st1;

    // Stack for storing minimum history
    stack<int> st2;

    // Push element into stack
    void push(int val) {

        // If min stack is empty OR current value
        // is smaller/equal to current minimum
        if (st2.empty() || val <= st2.top()) {
            st2.push(val);
        }

        // Push element into main stack
        st1.push(val);
    }

    // Remove top element
    void pop() {

        // If top element is current minimum,
        // remove from min stack too
        if (st1.top() == st2.top()) {
            st2.pop();
        }

        // Remove from main stack
        st1.pop();
    }

    // Return top element
    int top() {
        return st1.top();
    }

    // Return current minimum
    int getMin() {
        return st2.top();
    }
};

int main() {

    MinStack obj;

    // Test Case 1
    obj.push(-2);
    obj.push(0);
    obj.push(-3);

    cout << "Minimum: " << obj.getMin() << endl;

    obj.pop();

    cout << "Top: " << obj.top() << endl;
    cout << "Minimum: " << obj.getMin() << endl;

    // Test Case 2
    MinStack obj2;

    obj2.push(5);
    obj2.push(3);
    obj2.push(3);

    cout << "\nMinimum: " << obj2.getMin() << endl;

    obj2.pop();

    cout << "Minimum after pop: "
         << obj2.getMin() << endl;

    return 0;
}
