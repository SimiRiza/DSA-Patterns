/*
 * Problem:
 * LeetCode 797 - All Paths From Source to Target
 *
 * Approach:
 * 1. Use Depth-First Search (DFS) with backtracking starting from node 0.
 * 2. Maintain the current path in a temporary vector.
 * 3. Add the current node to the path.
 * 4. If the current node is the target node, store the path.
 * 5. Otherwise, recursively explore all neighboring nodes.
 * 6. Backtrack by removing the current node before returning.
 *
 * Time Complexity: O(2^N * N)
 * Space Complexity: O(N) (excluding the output)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void findPaths(vector<vector<int>>& graph, int u,
                   int target, vector<int>& temp) {

        temp.push_back(u);

        if (u == target) {
            res.push_back(temp);
        }

        for (int& v : graph[u]) {
            findPaths(graph, v, graph.size() - 1, temp);
        }

        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> temp;

        findPaths(graph, 0, n - 1, temp);

        return res;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> graph = {
        {1, 2},
        {3},
        {3},
        {}
    };

    vector<vector<int>> ans = obj.allPathsSourceTarget(graph);

    cout << "All Paths:\n";

    for (const auto& path : ans) {
        cout << "[ ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << "]\n";
    }

    return 0;
}