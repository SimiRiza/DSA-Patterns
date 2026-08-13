/*
 * Problem:
 * LeetCode 547 - Number of Provinces
 *
 * Approach:
 * 1. Convert the adjacency matrix into an adjacency list.
 * 2. Traverse each city using Breadth-First Search (BFS).
 * 3. If a city has not been visited, it starts a new province.
 * 4. Visit all cities connected to it and mark them as visited.
 * 5. Count the number of BFS traversals, which equals the number of provinces.
 *
 * Time Complexity: O(n²)
 * Space Complexity: O(n²)
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> visited(n);
        queue<int> q;
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected[i][j] == 1)
                    adj[i].push_back(j);
            }
        }

        int c = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                c++;

                q.push(i);
                visited[i] = 1;

                while (!q.empty()) {
                    visited[q.front()] = 1;

                    for (int node : adj[q.front()]) {
                        if (!visited[node])
                            q.push(node);
                    }

                    q.pop();
                }
            }
        }

        return c;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    cout << "Number of Provinces: "
         << obj.findCircleNum(isConnected) << endl;

    return 0;
}