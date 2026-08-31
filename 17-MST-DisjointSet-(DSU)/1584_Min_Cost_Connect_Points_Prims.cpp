/*
 * Problem:
 * LeetCode 1584 - Min Cost to Connect All Points
 *
 * Pattern:
 * Minimum Spanning Tree (MST) - Prim's Algorithm
 *
 * Approach:
 * 1. Build a complete undirected graph where the edge weight
 *    is the Manhattan distance between two points.
 * 2. Start Prim's Algorithm from point 0.
 * 3. Use a min-heap to always choose the minimum-weight edge
 *    connecting a new point.
 * 4. Skip a point if it is already visited.
 * 5. Add the selected edge's weight to the total cost.
 *
 * Time: O(E log E)
 * Space: O(E + V)
 *
 * Self Note:
 * The graph is complete, so E = V².
 * Therefore, this becomes O(V² log V) here.
 */

#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <functional>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        vector<vector<pair<int, int>>> adj(points.size());

        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {

                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);

                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        vector<int> visited(points.size());

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        int wt = 0;

        pq.push({0, -1, 0});

        while (!pq.empty()) {

            auto [weight, src, dest] = pq.top();
            pq.pop();

            if (visited[dest])
                continue;

            visited[dest] = 1;
            wt += weight;

            for (auto [neigh, dis] : adj[dest]) {

                if (!visited[neigh]) {
                    pq.push({dis, dest, neigh});
                }
            }
        }

        return wt;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> points = {
        {0, 0},
        {2, 2},
        {3, 10},
        {5, 2},
        {7, 0}
    };

    cout << "Minimum Cost: "
         << obj.minCostConnectPoints(points) << endl;

    return 0;
}