/*
 * Problem:
 * LeetCode 802 - Find Eventual Safe States
 *
 * Approach:
 * 1. Use DFS with three states:
 *      0 -> Unvisited
 *      1 -> Currently in the DFS path
 *      2 -> Safe / Completely processed
 * 2. If we encounter a node with state 1, a cycle exists,
 *    so the current node cannot be a safe node.
 * 3. If a neighbor is already in state 2, it is safe, so
 *    continue exploring.
 * 4. After all neighbors are safely processed, mark the current
 *    node as 2 and add it to the output.
 * 5. Sort the result because the answer must be in increasing order.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node,
             vector<int>& visited, vector<int>& output) {

        visited[node] = 1;

        for (int neigh : graph[node]) {

            if (visited[neigh] == 1) {
                return false;
            }

            if (visited[neigh] == 2) {
                continue;
            }

            if (visited[neigh] == 0) {
                if (!dfs(graph, neigh, visited, output)) {
                    return false;
                }
            }
        }

        visited[node] = 2;
        output.push_back(node);

        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> output;
        vector<int> visited(graph.size());

        for (int i = 0; i < graph.size(); i++) {
            if (visited[i] == 0) {
                dfs(graph, i, visited, output);
            }
        }

        sort(output.begin(), output.end());

        return output;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> graph = {
        {1, 2},
        {2, 3},
        {5},
        {0},
        {5},
        {},
        {}
    };

    vector<int> ans = obj.eventualSafeNodes(graph);

    cout << "Eventual Safe Nodes: ";

    for (int node : ans) {
        cout << node << " ";
    }

    cout << endl;

    return 0;
}