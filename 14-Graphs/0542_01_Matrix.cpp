/*
 * Problem:
 * LeetCode 542 - 01 Matrix
 *
 * Approach:
 * 1. Use Multi-Source BFS.
 * 2. Put all cells containing 0 into the queue initially with distance 0.
 * 3. Expand BFS from all 0s simultaneously.
 * 4. The first time an unvisited cell is reached, BFS guarantees
 *    that it has been reached from its nearest 0.
 * 5. Store the distance in the output matrix.
 *
 * Time Complexity: O(r * c)
 * Space Complexity: O(r * c)
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>> visited(r, vector<int>(c, 0));
        vector<vector<int>> out(r, vector<int>(c, 0));

        queue<pair<pair<int, int>, int>> q;

        // Put all 0s into the queue
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {

                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int pr = q.front().first.first;
            int pc = q.front().first.second;
            int step = q.front().second;

            q.pop();

            for (int k = 0; k < 4; k++) {

                int nr = pr + drow[k];
                int nc = pc + dcol[k];

                if (nr >= 0 && nc >= 0 &&
                    nr < r && nc < c &&
                    !visited[nr][nc]) {

                    visited[nr][nc] = 1;
                    out[nr][nc] = step + 1;

                    q.push({{nr, nc}, step + 1});
                }
            }
        }

        return out;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    vector<vector<int>> ans = obj.updateMatrix(mat);

    cout << "Distance Matrix:\n";

    for (const auto& row : ans) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}