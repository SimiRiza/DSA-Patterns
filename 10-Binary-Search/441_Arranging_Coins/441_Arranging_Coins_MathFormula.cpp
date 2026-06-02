/*
 * LeetCode 441 - Arranging Coins
 * Approach: Mathematical Formula (Quadratic Equation)
 *
 * From:
 *      k(k + 1) / 2 <= n
 *
 * Solving:
 *      k² + k - 2n = 0
 *
 * Using the quadratic formula:
 *      k = (sqrt(1 + 8n) - 1) / 2
 *
 * The floor of this value gives the maximum
 * number of complete rows.
 *
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        double root_part = 0.5 * sqrt(1LL + 8LL * n);
        return floor(root_part - 0.5);
    }
};

int main() {
    Solution sol;

    cout << "Test 1: " << sol.arrangeCoins(5) << endl; // Expected: 2
    cout << "Test 2: " << sol.arrangeCoins(8) << endl; // Expected: 3

    return 0;
}