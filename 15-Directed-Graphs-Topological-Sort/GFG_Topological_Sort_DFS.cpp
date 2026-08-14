/*
 * Problem:
 * Topological Sort of a Directed Acyclic Graph (DAG)
 *
 * Approach:
 * 1. Build an adjacency list from the directed edges.
 * 2. Perform DFS from every unvisited node.
 * 3. After visiting all neighbors of a node, add the node to output.
 * 4. This is postorder traversal, so reverse the output at the end
 *    to obtain the topological ordering.
 *
 * visited states:
 *      0 -> Not visited
 *      1 -> Currently being processed
 *      2 -> Fully processed
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V + E)
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node,
             vector<int>& visited, vector<int>& output) {

        visited[node] = 1;

        for (int neigh : adj[node]) {
            if (visited[neigh] == 0) {
                visited[neigh] = 1;
                dfs(adj, neigh, visited, output);
            }
        }

        visited[node] = 2;
        output.push_back(node);
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> output;
        vector<int> visited(V);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        for (int i = 0; i < V; i++) {
            if (visited[i] != 2) {
                dfs(adj, i, visited, output);
            }
        }

        reverse(output.begin(), output.end());

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