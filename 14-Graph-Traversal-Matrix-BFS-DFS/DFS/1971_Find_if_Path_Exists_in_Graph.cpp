/*
 * Problem:
 * LeetCode 1971 - Find if Path Exists in Graph
 *
 * Approach:
 * 1. Build an adjacency list from the given edges.
 * 2. Perform Breadth-First Search (BFS) starting from the source node.
 * 3. Mark each visited node to avoid processing it multiple times.
 * 4. Traverse all reachable nodes using a queue.
 * 5. If the destination node is visited, a valid path exists.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V + E)
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<int> visited(n);
        queue<int> q;

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        q.push(source);
        visited[source] = 1;

        while (!q.empty()) {
            for (int node : adj[q.front()]) {
                if (!visited[node]) {
                    visited[node] = 1;
                    q.push(node);
                }
            }

            q.pop();
        }

        return visited[destination];
    }
};

int main() {
    Solution obj;

    int n = 6;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {3, 5},
        {5, 4},
        {4, 3}
    };

    int source = 0;
    int destination = 5;

    if (obj.validPath(n, edges, source, destination))
        cout << "Path exists\n";
    else
        cout << "Path does not exist\n";

    return 0;
}