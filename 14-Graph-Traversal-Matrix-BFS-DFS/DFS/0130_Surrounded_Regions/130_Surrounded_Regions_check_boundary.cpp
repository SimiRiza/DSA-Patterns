/*
 * Problem:
 * LeetCode 130 - Surrounded Regions
 *
 * Approach:
 * 1. Start DFS from all boundary cells containing 'O'.
 * 2. Mark every boundary-connected 'O' as 'V' (safe).
 * 3. Traverse the entire board:
 *      - Convert remaining 'O' to 'X' (surrounded regions).
 *      - Convert 'V' back to 'O' (safe regions).
 *
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n) (recursion stack in the worst case)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void dfs(vector<vector<char>>& board, int i, int j) {
        board[i][j] = 'V';

        int drow[] = {0, 0, 1, -1};
        int dcol[] = {1, -1, 0, 0};

        for (int k = 0; k < 4; k++) {
            int nr = drow[k] + i;
            int nc = dcol[k] + j;

            if (nr >= 0 && nc >= 0 &&
                nr < board.size() && nc < board[0].size()) {

                if (board[nr][nc] == 'O') {
                    dfs(board, nr, nc);
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i == 0 || j == 0 || i == r - 1 || j == c - 1) {
                    if (board[i][j] == 'O')
                        dfs(board, i, j);
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'V') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main() {
    Solution obj;

    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    obj.solve(board);

    cout << "Board after solving:\n";

    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}