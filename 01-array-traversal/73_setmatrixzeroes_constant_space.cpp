#include <vector>
using namespace std;
// LeetCode: Set Matrix Zeroes
// Approach: Use 1st row and column instead of row and column arrays ->inplace marking
// Time Complexity: O(m * n)
// Space Complexity: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        // Flags to track whether the first row or first column
        // originally contained any zero
        int first_row0 = 0;
        int first_col0 = 0;

        // First pass:
        // Use the first row and first column as markers
        // to indicate which rows and columns should be zeroed
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {

                    // If zero is found in first row, mark it separately
                    if (i == 0) first_row0 = 1;

                    // If zero is found in first column, mark it separately
                    if (j == 0) first_col0 = 1;

                    // For all other cells, mark corresponding row and column
                    else {
                        matrix[i][0] = 0;  // mark row
                        matrix[0][j] = 0;  // mark column
                    }
                }
            }
        }

        // Second pass:
        // Zero out cells based on markers in first row and first column
        // Skip first row and first column for now
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {

                    // First row and first column are handled separately later
                    if (i == 0 || j == 0) continue;

                    matrix[i][j] = 0;
                }
            }
        }

        // If first row originally had a zero, zero the entire first row
        if (first_row0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // If first column originally had a zero, zero the entire first column
        if (first_col0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
