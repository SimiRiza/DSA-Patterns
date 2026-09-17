/*
 * Approach:
 * Use the Fibonacci recurrence:
 *     fib(n) = fib(n - 1) + fib(n - 2)
 *
 * Base cases:
 *     fib(0) = 0
 *     fib(1) = 1
 *
 * Time: O(2^n)
 * Space: O(n) - recursion stack
 *
 * Self Note:
 * This recursive solution is simple but not optimal.
 * DP / Iteration can reduce the time to O(n).
 */

#include <iostream>

using namespace std;

class Solution {
public:

    int fib(int n) {

        if (n == 0)
            return 0;

        if (n == 1)
            return 1;

        return fib(n - 1) + fib(n - 2);
    }
};

int main() {
    Solution obj;

    int n = 5;

    cout << "Fibonacci Number: "
         << obj.fib(n) << endl;

    return 0;
}