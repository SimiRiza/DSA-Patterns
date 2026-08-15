/*
 * Problem:
 * LeetCode 210 - Course Schedule II
 *
 * Approach:
 * 1. Build a directed graph where course -> prerequisite.
 * 2. Use DFS with three states:
 *      0 -> Not visited
 *      1 -> Currently in the DFS path
 *      2 -> Completely processed
 * 3. If we encounter a node with state 1, a cycle exists,
 *    so completing all courses is impossible.
 * 4. After processing all neighbors, add the current course
 *    to the output.
 * 5. Because courses are added in DFS postorder, the resulting
 *    order is already a valid course order for this graph.
 *
 * Time Complexity: O(V + E)
 * Space Complexity: O(V + E)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& visited,
             int node, vector<int>& output) {

        visited[node] = 1;

        for (int neigh : adj[node]) {
            if (visited[neigh] == 0) {
                if (!dfs(adj, visited, neigh, output))
                    return false;
            }
            else if (visited[neigh] == 1) {
                return false;
            }
        }

        visited[node] = 2;
        output.push_back(node);

        return true;
    }

    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites) {

        vector<int> visited(numCourses);
        vector<int> output;
        vector<vector<int>> adj(numCourses);

        for (auto edge : prerequisites) {
            adj[edge[0]].push_back(edge[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (!dfs(adj, visited, i, output))
                    return {};
            }
        }

        return output;
    }
};

int main() {
    Solution obj;

    int numCourses = 4;

    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    vector<int> ans = obj.findOrder(numCourses, prerequisites);

    cout << "Course Order: ";

    if (ans.empty()) {
        cout << "No valid order";
    }
    else {
        for (int course : ans) {
            cout << course << " ";
        }
    }

    cout << endl;

    return 0;
}