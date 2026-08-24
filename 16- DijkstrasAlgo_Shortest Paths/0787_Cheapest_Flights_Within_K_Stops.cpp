/*
 * Problem:
 * LeetCode 787 - Cheapest Flights Within K Stops
 *
 * Approach:
 * Use BFS with a queue while keeping track of:
 *     - stops
 *     - current node
 *     - current cost
 *
 * We explore the graph level by level, where each level represents
 * taking one more flight.
 *
 * dist[node] stores the cheapest cost found so far to reach that node.
 *
 * We start with stops = -1 because the source itself is not a stop.
 * Therefore, after taking the first flight:
 *     stops + 1 = 0
 *
 * We only continue if:
 *     stops + 1 <= k
 *
 * Time Complexity: O(K * E) approximately
 * Space Complexity: O(V + E)
 *
 * Self Note:
 * Normal Dijkstra is not directly suitable with only dist[node],
 * because the number of stops also affects the answer.
 * Here, BFS naturally processes routes according to their number
 * of flights/stops.
 */

#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        queue<
            pair<int, pair<int, int>>
        > pq;

        pq.push({-1, {src, 0}});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        vector<vector<pair<int, int>>> adj(n);

        for (auto arr : flights) {
            adj[arr[0]].push_back({arr[1], arr[2]});
        }

        while (!pq.empty()) {

            int stops = pq.front().first;
            int node = pq.front().second.first;
            int cost = pq.front().second.second;

            pq.pop();

            for (auto neigh_cost : adj[node]) {

                int neigh = neigh_cost.first;
                int curr_cost = neigh_cost.second;

                if (stops + 1 <= k &&
                    cost + curr_cost < dist[neigh]) {

                    dist[neigh] = cost + curr_cost;

                    pq.push({
                        stops + 1,
                        {neigh, cost + curr_cost}
                    });
                }
            }
        }

        if (dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};

int main() {
    Solution obj;

    int n = 4;

    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}
    };

    int src = 0;
    int dst = 3;
    int k = 1;

    cout << "Cheapest Price: "
         << obj.findCheapestPrice(n, flights, src, dst, k)
         << endl;

    return 0;
}