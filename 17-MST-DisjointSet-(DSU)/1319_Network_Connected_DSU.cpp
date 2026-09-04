/*
 * Problem:
 * LeetCode 1319 - Number of Operations to Make Network Connected
 *
 * Pattern:
 * DSU (Disjoint Set Union)
 *
 * Approach:
 * 1. If cables < n - 1, connecting all computers is impossible.
 * 2. Use DSU to form connected components.
 * 3. Count the number of components.
 * 4. To connect 'components' groups, we need components - 1 operations.
 *
 * DSU uses:
 *     - Path Compression
 *     - Union by Rank
 *
 * Time: O(E * α(V)) ≈ O(E)
 * Space: O(V)
 *
 * Self Note:
 * Connecting C components always needs C - 1 operations.
 * The n - 1 cable check is necessary because a connected graph
 * with n nodes needs at least n - 1 edges.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);  // Path Compression
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        // Union by Rank
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        // Need at least n-1 cables
        if (connections.size() < n - 1)
            return -1;

        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Build components
        for (auto& connection : connections) {
            unite(connection[0], connection[1]);
        }

        // Count components
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                components++;
        }

        return components - 1;
    }
};

int main() {
    Solution obj;

    int n = 4;

    vector<vector<int>> connections = {
        {0, 1},
        {0, 2},
        {1, 2}
    };

    cout << "Minimum Operations: "
         << obj.makeConnected(n, connections)
         << endl;

    return 0;
}