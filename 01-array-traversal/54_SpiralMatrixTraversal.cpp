
#include <bits/stdc++.h>
using namespace std;

// File: SpiralMatrixTraversal.cpp
// Problem: Print elements of a 2D matrix in spiral order
// Approach: Boundary shrinking technique

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;   // stores the spiral order result
        
        // Edge case: empty matrix
        if (matrix.size() == 0) return ans;
        
        // Initialize boundaries
        int tr = 0;                       // top row
        int br = matrix.size() - 1;       // bottom row
        int lc = 0;                       // left column
        int rc = matrix[0].size() - 1;    // right column
        
        // Continue while boundaries are valid
        while (tr <= br && lc <= rc) {
            
            // 1. Print the top row (left to right)
            for (int i = lc; i <= rc; i++) {
                ans.push_back(matrix[tr][i]);
            }
            
            // 2. Print the right column (top to bottom)
            for (int i = tr + 1; i < br; i++) {
                ans.push_back(matrix[i][rc]);
            }
            
            // 3. Print the bottom row (right to left)
            // Only if top row is not same as bottom row
            if (tr != br) {
                for (int i = rc; i >= lc; i--) {
                    ans.push_back(matrix[br][i]);
                }
            }
            
            // 4. Print the left column (bottom to top)
            // Only if left column is not same as right column
            if (lc != rc) {
                for (int i = br - 1; i >= tr + 1; i--) {
                    ans.push_back(matrix[i][lc]);
                }
            }
            
            // Move boundaries inward
            tr++;
            br--;
            lc++;
            rc--;
        }
        
        return ans;
    }
};


int main() {
    Solution sol;

    // 2D vector syntax:
    // vector<vector<int>> name = { {row1}, {row2}, ... };

    vector<vector<int>> matrix = {
        { 1,  2,  3,  4,  5,  6,  7},
        { 8,  9, 10, 11, 12, 13, 14},
        {15, 16, 17, 18, 19, 20, 21},
        {22, 23, 24, 25, 26, 27, 28},
        {29, 30, 31, 32, 33, 34, 35}
    };

    vector<int> result = sol.spiralOrder(matrix);

    // Traversing 1D vector
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}

    