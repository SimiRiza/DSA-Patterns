/*
 * Problem:
 * LeetCode 994 - Rotting Oranges
 *
 * Approach:
 * 1. Push all initially rotten oranges into a queue with time = 0.
 * 2. Count the total number of fresh oranges.
 * 3. Perform Multi-Source BFS:
 *      - Each rotten orange infects its four adjacent fresh oranges.
 *      - Newly rotten oranges are pushed into the queue with time + 1.
 * 4. Track:
 *      - tm     = maximum time taken.
 *      - rotcnt = number of fresh oranges that became rotten.
 * 5. If all fresh oranges are rotten, return tm.
 *    Otherwise, return -1.
 *
 * Time Complexity: O(n * m)
 * Space Complexity: O(n * m)
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int visited[n][m];

        queue<pair<pair<int, int>, int>> q;

        int cntfresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = 0;

                if (grid[i][j] == 2) {
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }
                else if (grid[i][j] == 1) {
                    cntfresh++;
                }
            }
        }

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        int tm = 0;
        int rotcnt = 0;

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            tm = max(tm, t);

            int nr, nc;

            for (int i = 0; i < 4; i++) {
                nr = r + drow[i];
                nc = c + dcol[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    if (visited[nr][nc] != 1 && grid[nr][nc] == 1) {
                        q.push({{nr, nc}, t + 1});
                        rotcnt++;
                        visited[nr][nc] = 1;
                    }
                }
            }

            q.pop();
        }

        if (rotcnt == cntfresh)
            return tm;

        return -1;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    cout << "Minimum Time: " << obj.orangesRotting(grid) << endl;

    return 0;
}