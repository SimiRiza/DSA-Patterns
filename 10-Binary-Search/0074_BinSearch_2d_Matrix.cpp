/*
 * LeetCode 74 - Search a 2D Matrix
 * Approach: Binary Search on Flattened Matrix
 *
 * Idea:
 * - Treat the 2D matrix as a single sorted 1D array.
 * - Use binary search on indices from 0 to (rows * cols - 1).
 * - Convert the 1D index back to 2D coordinates:
 *      row = idx / cols
 *      col = idx % cols
 *
 * Time Complexity: O(log(rows * cols))
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int li = 0, ri = 0;

        int start = 0, end = rows * cols - 1, mid;

        while (start <= end) {
            mid = start + (end - start) / 2;

            // Convert flattened index into matrix coordinates
            li = mid / cols;
            ri = mid % cols;

            if (matrix[li][ri] < target) {
                start = mid + 1;
            }
            else if (matrix[li][ri] > target) {
                end = mid - 1;
            }
            else {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> matrix1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    cout << obj.searchMatrix(matrix1, 3) << endl;   // Expected: 1
    cout << obj.searchMatrix(matrix1, 13) << endl;  // Expected: 0

    return 0;
}