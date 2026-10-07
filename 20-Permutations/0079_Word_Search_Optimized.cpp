#include <bits/stdc++.h>
using namespace std;

/*
Problem: LeetCode 79 - Word Search
Pattern: DFS + Backtracking

Approach:
- Start DFS from every cell matching word[0].
- Check whether the current cell matches word[idx].
- Mark the cell as visited.
- Explore all 4 directions for the next character.
- If the last character matches, return true.
- Backtrack by unmarking the cell.

Time: O(m * n * 4^L)
Space: O(m * n) visited + O(L) recursion stack
       where L = word.length()

Self Note:
- This is better than the previous version because we don't
  maintain a temp string.
- idx directly tells us which character we are searching for.
- A cell can be used only once in the current path.
*/

class Solution {
public:

    bool explore_retreat(vector<vector<char>>& board,
                         string& word,
                         int idx, int i, int j,
                         vector<vector<bool>>& visited) {

        if(board[i][j] == word[idx]) {

            if(idx == word.size() - 1)
                return true;

            visited[i][j] = true;

            int drow[4] = {0, 0, 1, -1};
            int dcol[4] = {1, -1, 0, 0};

            for(int k = 0; k < 4; k++) {

                int nrow = i + drow[k];
                int ncol = j + dcol[k];

                if(nrow >= 0 && nrow < board.size() &&
                   ncol >= 0 && ncol < board[0].size() &&
                   !visited[nrow][ncol]) {

                    if(explore_retreat(board, word,
                                       idx + 1,
                                       nrow, ncol,
                                       visited))
                        return true;
                }
            }

            // Backtrack
            visited[i][j] = false;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(
            m, vector<bool>(n, false)
        );

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == word[0]) {

                    if(explore_retreat(board, word,
                                       0, i, j, visited))
                        return true;
                }
            }
        }

        return false;
    }
};

int main() {

    Solution sol;

    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word = "ABCCED";

    cout << boolalpha << sol.exist(board, word) << endl;

    return 0;
}