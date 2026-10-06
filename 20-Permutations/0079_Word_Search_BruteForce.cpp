#include <bits/stdc++.h>
using namespace std;

/*
Problem: LeetCode 79 - Word Search
Pattern: DFS + Backtracking

Approach:
- Start DFS from every cell matching word[0].
- If the current cell matches word[idx], add it to temp.
- Mark the cell as visited.
- Explore all 4 directions.
- Backtrack by removing the character and unmarking the cell.

Time: O(m * n * 4^L)
Space: O(m * n) visited + O(L) recursion/temp
       where L = word.length()

Self Note:
- A cell cannot be used twice in the same path.
- visited prevents revisiting a cell.
- After exploring all 4 directions, undo the choice:
      temp.pop_back();
      visited[i][j] = false;

Note:
This version still maintains temp and therefore does extra work.
A more optimized version can directly use idx without temp.
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
            temp.pop_back();
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
// self-note to avoid TLE:
// 1. Use fixed arrays for constant 4-direction movement.
//    Creating direction vectors inside every DFS call caused TLE.

// 2. Check temp == word AFTER adding the current character.
//    Otherwise single-character words like "a" fail.

// 3. Backtracking requires undoing BOTH choices:
//    temp.pop_back() and visited[i][j] = false.

// 4. Pass frequently reused strings by reference to avoid unnecessary copies.
