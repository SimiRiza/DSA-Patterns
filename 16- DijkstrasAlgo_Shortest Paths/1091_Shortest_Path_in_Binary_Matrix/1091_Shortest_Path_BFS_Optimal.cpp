/*
 * Problem:
 * LeetCode 1091 - Shortest Path in Binary Matrix
 *
 * Approach:
 * Use BFS from the top-left cell and explore all 8 directions.
 * Since every move has equal cost (1), BFS guarantees the shortest path.
 *
 * Intuition:
 * BFS explores cells level by level.
 * Therefore, the first time we reach the destination, we have found
 * the shortest path.
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2)
 *
 * Self Note:
 * Dijkstra is actually overkill here because every move has weight 1.
 * BFS is the better approach for an unweighted graph.
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> visited(n, vector<int>(n));

        int drow[] = {0, 0, -1, 1, -1, -1, 1, 1};
        int dcol[] = {-1, 1, 0, 0, 1, -1, 1, -1};

        queue<pair<int, pair<int, int>>> q;

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        q.push({1, {0, 0}});
        visited[0][0] = 1;

        int d;

        while (!q.empty()) {
            d = q.front().first;

            int i = q.front().second.first;
            int j = q.front().second.second;

            q.pop();

            for (int k = 0; k < 8; k++) {
                int nr = i + drow[k];
                int nc = j + dcol[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n) {

                    if (grid[nr][nc] == 0 &&
                        !visited[nr][nc]) {

                        if (nr == n - 1 && nc == n - 1)
                            return d + 1;

                        q.push({d + 1, {nr, nc}});
                        visited[nr][nc] = 1;
                    }
                }
            }
        }

        if (!visited[n - 1][n - 1]) {
            return -1;
        }

        return d;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {0, 1},
        {1, 0}
    };

    cout << obj.shortestPathBinaryMatrix(grid) << endl;

    return 0;
}