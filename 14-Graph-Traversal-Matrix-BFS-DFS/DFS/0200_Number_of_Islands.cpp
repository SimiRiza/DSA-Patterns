/*
 * Problem:
 * LeetCode 200 - Number of Islands
 *
 * Approach:
 * 1. Traverse every cell in the grid.
 * 2. When an unvisited land cell ('1') is found,
 *    increment the island count.
 * 3. Perform DFS to mark all connected land cells
 *    as visited by changing them to '0'.
 * 4. Continue until the entire grid has been processed.
 *
 * Time Complexity: O(n * m)
 * Space Complexity: O(n * m) (recursion stack in the worst case)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void make_neighbours_zero(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';

        int drow[] = {1, -1, 0, 0};
        int dcol[] = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int new_i = i + drow[k];
            int new_j = j + dcol[k];

            if (new_i >= 0 && new_i < grid.size() &&
                new_j >= 0 && new_j < grid[0].size()) {

                if (grid[new_i][new_j] == '1') {
                    grid[new_i][new_j] = '0';
                    make_neighbours_zero(grid, new_i, new_j);
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] == '1') {
                    make_neighbours_zero(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    Solution obj;

    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    cout << "Number of Islands: " << obj.numIslands(grid) << endl;

    return 0;
}