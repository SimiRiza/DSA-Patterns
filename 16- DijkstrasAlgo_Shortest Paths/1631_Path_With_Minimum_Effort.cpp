/*
 * Problem:
 * LeetCode 1631 - Path With Minimum Effort
 *
 * Approach:
 * Use Dijkstra's algorithm.
 *
 * Unlike normal shortest path, the cost of a path is NOT the sum
 * of edge weights. The effort of a path is the maximum height
 * difference encountered along that path.
 *
 * For every move:
 *     curr_effort = max(current path effort, current height difference)
 *
 * We always process the cell with the minimum known effort using
 * a min-heap.
 *
 * Intuition:
 * We want a path where the largest single height difference is
 * as small as possible.
 *
 * Time Complexity: O(m * n * log(m * n))
 * Space Complexity: O(m * n)
 */

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <climits>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        int drow[] = {0, 0, -1, 1};
        int dcol[] = {-1, 1, 0, 0};

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while (!pq.empty()) {

            int effort = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;

            pq.pop();

            if (effort > dist[i][j]) continue;

            for (int k = 0; k < 4; k++) {

                int nr = i + drow[k];
                int nc = j + dcol[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {

                    int curr_effort =
                        max(effort, abs(grid[i][j] - grid[nr][nc]));

                    if (curr_effort < dist[nr][nc]) {
                        dist[nr][nc] = curr_effort;
                        pq.push({curr_effort, {nr, nc}});
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    cout << "Minimum Effort: "
         << obj.minimumEffortPath(grid) << endl;

    return 0;
}