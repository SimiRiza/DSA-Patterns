/*
 * Problem:
 * LeetCode 48 - Rotate Image
 *
 * Approach:
 * 1. Transpose the matrix by swapping matrix[i][j] with matrix[j][i].
 * 2. Reverse every row of the transposed matrix.
 * 3. The matrix is rotated 90° clockwise in-place.
 *
 * Time Complexity: O(n²)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse every row to obtain a 90° clockwise rotation
        for (auto &arr : matrix) {
            reverse(arr.begin(), arr.end());
        }
    }
};

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main() {
    // Test Case:
    // 1 2 3
    // 4 5 6
    // 7 8 9

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution obj;
    obj.rotate(matrix);

    cout << "Rotated Matrix:" << endl;
    printMatrix(matrix);

    // Expected Output:
    // 7 4 1
    // 8 5 2
    // 9 6 3

    return 0;
}