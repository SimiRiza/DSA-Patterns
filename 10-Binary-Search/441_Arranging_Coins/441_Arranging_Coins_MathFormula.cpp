/*
 * LeetCode 441 - Arranging Coins
 * Approach: Binary Search
 *
 * Search for the largest number of complete rows (k)
 * such that k * (k + 1) / 2 <= n.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int start = 0, end = n - 1;
        int mid, val, ans = 0;
        long long stair;

        while (start <= end) {
            mid = start + (end - start) / 2;

            // Convert mid (0-based) to row count
            val = mid + 1;

            // Number of coins needed for 'val' rows
            stair = val * (val + 1LL) / 2LL;

            if (stair < n) {
                ans = val;          // Valid answer so far
                start = mid + 1;    // Try larger row count
            }
            else if (stair == n) {
                return val;         // Exact match found
            }
            else {
                end = mid - 1;      // Too many coins used
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    cout << "Test 1: " << sol.arrangeCoins(5) << endl; // Expected: 2
    cout << "Test 2: " << sol.arrangeCoins(8) << endl; // Expected: 3

    return 0;
}