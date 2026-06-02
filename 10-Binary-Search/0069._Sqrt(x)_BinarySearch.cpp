/*
    LeetCode 69 - Sqrt(x)
    Approach: Binary Search

    Description:
    Search for the largest number whose square is less than or equal to x.
    Use binary search on the range [0, x].

    Time Complexity: O(log x)
    Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int start = 0, end = x, mid;
        long long ans = 0, sq_val;

        while (start <= end) {

            // Prevent overflow while finding middle
            mid = start + (end - start) / 2;

            // Compute square in long long to avoid overflow
            sq_val = 1LL * mid * mid;

            if (sq_val > x) {
                end = mid - 1;
            }
            else {
                // Current mid is a valid answer
                ans = mid;

                // Try to find a larger valid square root
                start = mid + 1;
            }
        }

        return static_cast<int>(ans);
    }
};

int main() {
    Solution sol;

    // Test Case 1
    cout << "sqrt(4) = " << sol.mySqrt(4) << endl;

    // Test Case 2
    cout << "sqrt(8) = " << sol.mySqrt(8) << endl;

    return 0;
}