/*
 * Problem:
 * LeetCode 207 - Course Schedule
 *
 * Approach:
 * 1. Represent courses as a directed graph using an adjacency list.
 * 2. Perform DFS from every unvisited node.
 * 3. Maintain:
 *      - visited  : Nodes that have been visited.
 *      - path_vis : Nodes currently in the DFS recursion stack.
 * 4. During DFS:
 *      - If an unvisited neighbor forms a cycle, return true.
 *      - If a neighbor is already in the current recursion stack,
 *        a cycle exists.
 * 5. If any cycle is found, all courses cannot be completed.
 *    Otherwise, all courses can be finished.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V + E)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj,
             vector<int>& visited,
             vector<int>& path_vis) {

        visited[node] = 1;
        path_vis[node] = 1;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited, path_vis))
                    return true;
            }
            else if (path_vis[neighbor]) {
                return true;
            }
        }

        path_vis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for (auto arr : prerequisites) {
            adj[arr[0]].push_back(arr[1]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> path_vis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, path_vis))
                    return false;
            }
        }

        return true;
    }
};

int main() {
    Solution obj;

    int numCourses = 2;
    vector<vector<int>> prerequisites = {
        {1, 0}
    };

    if (obj.canFinish(numCourses, prerequisites))
        cout << "All courses can be finished." << endl;
    else
        cout << "Cycle detected. Cannot finish all courses." << endl;

    return 0;
}