/*
 * LeetCode 278 - First Bad Version
 * Approach: Binary Search
 *
 * Idea:
 * Treat versions as a sorted space:
 * Good Good Good Bad Bad Bad
 * Use binary search to find the first bad version.
 *
 * Time Complexity : O(log n)
 * Space Complexity: O(1)
 */

#include <iostream>

using namespace std;

// Mock API for local testing
int firstBad = 4;

bool isBadVersion(int version) {
    return version >= firstBad;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 0, end = n - 1, check;

        while (start <= end) {

            // Find middle index safely
            check = start + (end - start) / 2;

            // Convert index to version number (1-based)
            if (isBadVersion(check + 1)) {

                // Current version is bad,
                // search for an earlier bad version
                end = check - 1;
            }
            else {

                // Current version is good,
                // first bad version must be on the right
                start = check + 1;
            }
        }

        // Convert index back to version number
        return start + 1;
    }
};

int main() {
    Solution sol;

    firstBad = 4;
    cout << "Test 1: " << sol.firstBadVersion(5) << endl; // Expected: 4

    firstBad = 1;
    cout << "Test 2: " << sol.firstBadVersion(1) << endl; // Expected: 1

    return 0;
}