/*
 * Problem:
 * LeetCode 785 - Is Graph Bipartite?
 *
 * Approach:
 * 1. Use BFS to traverse each connected component.
 * 2. Assign each node one of two colors: 0 or 1.
 * 3. Every pair of connected nodes must have different colors.
 * 4. If an already-colored neighbor has the same color as the
 *    current node, the graph is not bipartite.
 * 5. Start BFS from every unvisited node because the graph can
 *    contain multiple disconnected components.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool bfs(vector<vector<int>>& graph, queue<int>& q,
             vector<int>& colored) {

        while (!q.empty()) {
            int curr_node = q.front();
            int curr_color = colored[curr_node];

            for (int node : graph[curr_node]) {
                if (colored[node] == -1) {

                    if (curr_color == 0)
                        colored[node] = 1;
                    else if (curr_color == 1)
                        colored[node] = 0;

                    q.push(node);
                }
                else {
                    if (colored[node] == 0) {
                        if (curr_color == 0)
                            return false;
                    }

                    if (colored[node] == 1) {
                        if (curr_color == 1)
                            return false;
                    }
                }
            }

            q.pop();
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        vector<int> colored(graph.size(), -1);

        for (int i = 0; i < graph.size(); i++) {
            if (colored[i] == -1) {
                q.push(i);
                colored[i] = 0;

                if (bfs(graph, q, colored) == false)
                    return false;
            }
        }

        return true;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    if (obj.isBipartite(graph))
        cout << "Graph is Bipartite\n";
    else
        cout << "Graph is not Bipartite\n";

    return 0;
}