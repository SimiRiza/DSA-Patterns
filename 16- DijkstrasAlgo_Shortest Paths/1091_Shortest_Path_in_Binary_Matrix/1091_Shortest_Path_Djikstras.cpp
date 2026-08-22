/*
 * Problem:
 * LeetCode 1091 - Shortest Path in Binary Matrix
 *
 * Approach:
 * 1. Treat every 0-cell as a node in an unweighted graph.
 * 2. From each cell, we can move in 8 directions.
 * 3. Use a min-heap to always process the cell with the smallest
 *    current distance.
 * 4. Maintain dist[i][j] as the shortest known path length to
 *    reach cell (i, j).
 * 5. If the destination remains unreachable, return -1.
 *
 * Time Complexity: O(n^2 log(n^2))
 * Space Complexity: O(n^2)
 */

#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//  Self Note:
//  Dijkstra is overkill here because every move has weight 1.
//  BFS is the better approach for this problem.

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> dist(
            n, vector<int>(n, INT_MAX)
        );

        int drow[] = {0, 0, -1, 1, -1, -1, 1, 1};
        int dcol[] = {-1, 1, 0, 0, 1, -1, 1, -1};

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        pq.push({1, {0, 0}});
        dist[0][0] = 1;

        while (!pq.empty()) {

            int d = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;

            pq.pop();

            if (d > dist[i][j])
                continue;

            for (int k = 0; k < 8; k++) {

                int nr = i + drow[k];
                int nc = j + dcol[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n) {

                    if (grid[nr][nc] == 0) {

                        if (d + 1 < dist[nr][nc]) {
                            dist[nr][nc] = d + 1;
                            pq.push({d + 1, {nr, nc}});
                        }
                    }
                }
            }
        }

        if (dist[n - 1][n - 1] == INT_MAX)
            return -1;

        return dist[n - 1][n - 1];
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {0, 1},
        {1, 0}
    };

    cout << "Shortest Path: "
         << obj.shortestPathBinaryMatrix(grid) << endl;

    return 0;
}