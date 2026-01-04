#include <vector>
using namespace std;

// LeetCode: Set Matrix Zeroes
// Approach: Use extra space with vector flags for rows and columns
// Time Complexity: O(m * n)
// Space Complexity: O(m + n)
//
// Note:
// - unordered_set can also be used to store rows and columns containing zeroes.
// - However, vectors are preferred here because row and column indices are dense
//   and known in advance, making vectors more memory-efficient and cache-friendly.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        // Vector flags to mark which rows and columns should be zeroed
        vector<int> row(m, 0);
        vector<int> col(n, 0);

        // First pass:
        // Identify all rows and columns that contain at least one zero
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;  // mark row
                    col[j] = 1;  // mark column
                }
            }
        }

        // Second pass:
        // Set matrix elements to zero if their row or column is marked
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
