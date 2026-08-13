/*
 * Problem:
 * Topological Sort of a Directed Acyclic Graph (DAG)
 *
 * Approach:
 * 1. Build an adjacency list from the directed edges.
 * 2. Calculate the indegree of every vertex.
 * 3. Add all vertices with indegree 0 to the queue.
 * 4. Repeatedly remove a vertex from the queue and add it to
 *    the topological ordering.
 * 5. Decrease the indegree of its neighbors.
 * 6. When a neighbor's indegree becomes 0, add it to the queue.
 *
 * This is Kahn's Algorithm for Topological Sort.
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
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        int e = edges.size();

        vector<vector<int>> adj(V);
        vector<int> indeg(V);
        vector<int> output;
        vector<int> visited(V);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indeg[v]++;
        }

        queue<int> q;

        for (int i = 0; i < V; i++) {
            if (indeg[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }

        while (!q.empty()) {
            int node = q.front();

            output.push_back(node);

            for (int neigh : adj[node]) {
                indeg[neigh]--;

                if (!visited[neigh] && indeg[neigh] == 0) {
                    q.push(neigh);
                    visited[neigh] = 1;
                }
            }

            q.pop();
        }

        return output;
    }
};

int main() {
    Solution obj;

    int V = 6;

    vector<vector<int>> edges = {
        {5, 2},
        {5, 0},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };

    vector<int> ans = obj.topoSort(V, edges);

    cout << "Topological Sort: ";

    for (int node : ans) {
        cout << node << " ";
    }

    cout << endl;

    return 0;
}