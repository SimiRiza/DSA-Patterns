/*
 * Problem:
 * LeetCode 743 - Network Delay Time
 *
 * Approach:
 * 1. Build a weighted adjacency list from the given edges.
 * 2. Use Dijkstra's algorithm with a min-heap (priority queue).
 * 3. dist[i] stores the shortest time needed to reach node i from k.
 * 4. Whenever a shorter path to a neighbor is found, update its
 *    distance and push it into the priority queue.
 * 5. The answer is the maximum shortest distance among all nodes.
 *    If any node is unreachable, return -1.
 *
 * Time Complexity: O((V + E) log V)
 * Space Complexity: O(V + E)
 */

#include <functional>
#include <iostream>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto edge : times) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<int> dist(n + 1, INT_MAX);

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {

            int time = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if (time > dist[node])
                continue;

            for (auto edge : adj[node]) {

                int next = edge.first;
                int weight = edge.second;

                if (time + weight < dist[next]) {
                    dist[next] = time + weight;
                    pq.push({dist[next], next});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> times = {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };

    int n = 4;
    int k = 2;

    cout << "Network Delay Time: "
         << obj.networkDelayTime(times, n, k) << endl;

    return 0;
}