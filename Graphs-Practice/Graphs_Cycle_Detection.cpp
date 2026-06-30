#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool hasCycle(int V, vector<vector<int>>& adj) {

        unordered_set<int> visited;

        for (int i = 0; i < V; i++) {

            if (visited.count(i))
                continue;

            queue<pair<int, int>> q;
            q.push({i, -1});
            visited.insert(i);

            while (!q.empty()) {

                int curr_node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for (int neighbour : adj[curr_node]) {

                    if (!visited.count(neighbour)) {
                        visited.insert(neighbour);
                        q.push({neighbour, curr_node});
                    }
                    else if (neighbour != parent) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    int V = 5;

    // Adjacency List
    vector<vector<int>> adj = {
        {1},          // 0
        {0, 2, 4},    // 1
        {1, 3},       // 2
        {2, 4},       // 3
        {3, 1}        // 4
    };

    if (sol.hasCycle(V, adj))
        cout << "Cycle Exists\n";
    else
        cout << "No Cycle\n";

    return 0;
}