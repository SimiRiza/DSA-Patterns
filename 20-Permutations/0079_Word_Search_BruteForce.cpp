#include <bits/stdc++.h>
using namespace std;

/*
Problem: LeetCode 79 - Word Search
Pattern: DFS + Backtracking

Approach:
- Start DFS from every cell matching word[0].
- Match the current character.
- Move in 4 directions.
- Mark the cell visited so it cannot be reused.
- Backtrack by unmarking the cell and removing the character.

Time: Can become exponential
Space: O(m*n) visited + recursion stack

Self Note:
This is a brute-force/backtracking version.

IMPORTANT:
This version can TLE because:
- temp string is maintained unnecessarily.
- temp == word is checked repeatedly.
- idx is carried separately.
- We start DFS from every matching cell.

A better version directly checks:
    board[i][j] == word[idx]

and returns true when:
    idx == word.size() - 1

So this version is mainly for understanding
the DFS + backtracking idea.

Core pattern:
    choose cell
    → mark visited
    → explore 4 directions
    → undo visited

Also:
A cell can be used only once in the current path.
*/

class Solution {
public:

    bool explore_retreat(vector<vector<char>>& board,
                         string word,
                         string& temp,
                         int idx,
                         int i,
                         int j,
                         vector<vector<bool>>& visited) {

        if(temp == word)
            return true;

        if(board[i][j] == word[idx]) {

            temp += board[i][j];

            if(temp == word)
                return true;

            visited[i][j] = true;

            vector<int> drow = {0, 0, 1, -1};
            vector<int> dcol = {1, -1, 0, 0};

            for(int k = 0; k < 4; k++) {

                int nrow = i + drow[k];
                int ncol = j + dcol[k];

                if(nrow >= 0 && nrow < board.size() &&
                   ncol >= 0 && ncol < board[0].size() &&
                   !visited[nrow][ncol]) {

                    if(explore_retreat(board, word, temp,
                                       idx + 1, nrow, ncol, visited))
                        return true;
                }
            }

            // Backtrack
            if(!temp.empty())
                temp.pop_back();

            visited[i][j] = false;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == word[0]) {

                    string temp = "";

                    if(explore_retreat(board, word, temp,
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