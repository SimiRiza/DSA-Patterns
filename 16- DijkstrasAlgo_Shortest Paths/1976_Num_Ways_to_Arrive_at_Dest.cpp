/*
 * Problem:
 * LeetCode 1976 - Number of Ways to Arrive at Destination
 *
 * Pattern:
 * Dijkstra + Counting Number of Shortest Paths
 *
 * Approach:
 * Use Dijkstra's algorithm to find the shortest distance to every node.
 *
 * Along with dist[], maintain ways[]:
 *     ways[i] = number of shortest paths to reach node i.
 *
 * For every neighbor:
 *
 * 1. If we find a SHORTER path:
 *        dist[neigh] = d + wt
 *        ways[neigh] = ways[node]
 *
 *    Because every shortest path to node comes through the current node.
 *
 * 2. If we find ANOTHER path with the SAME shortest distance:
 *        ways[neigh] += ways[node]
 *
 * Finally, ways[n-1] gives the number of shortest paths to the destination.
 *
 * Time Complexity: O((V + E) log V)
 * Space Complexity: O(V + E)
 *
 * Self Note:
 * Use long long for distances because the total path distance
 * can become larger than the range of int.
 *
 * MOD is used because the number of shortest paths can become huge.
 * The required answer is modulo 1e9 + 7.
 */

#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const long long MOD = 1e9 + 7;

        vector<long long> dist(n, LLONG_MAX);

        vector<int> ways(n, 0);

        vector<vector<pair<int, int>>> adj(n);

        for (auto arr : roads) {
            adj[arr[0]].push_back({arr[1], arr[2]});
            adj[arr[1]].push_back({arr[0], arr[2]});
        }

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        pq.push({0, 0});

        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {

            long long d = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for (auto node_wt : adj[node]) {

                int neigh = node_wt.first;
                int wt = node_wt.second;

                if (d + wt < dist[neigh]) {

                    dist[neigh] = d + wt;

                    ways[neigh] = ways[node];

                    pq.push({dist[neigh], neigh});
                }

                else if (d + wt == dist[neigh]) {

                    ways[neigh] =
                        (ways[neigh] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1] % MOD;
    }
};

int main() {
    Solution obj;

    int n = 7;

    vector<vector<int>> roads = {
        {0, 6, 7},
        {0, 1, 2},
        {1, 2, 3},
        {1, 3, 3},
        {6, 3, 3},
        {3, 5, 1},
        {6, 5, 1},
        {2, 5, 1},
        {0, 4, 5},
        {4, 6, 2}
    };

    cout << "Number of Shortest Paths: "
         << obj.countPaths(n, roads) << endl;

    return 0;
}