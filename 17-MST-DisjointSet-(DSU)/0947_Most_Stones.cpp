/*
 * Approach:
 * 1. Treat every stone as a node.
 * 2. Connect two stones if they share the same row or column.
 * 3. Find the number of connected components.
 * 4. From each component, exactly one stone must remain.
 *     Maximum removed = n - number of components
 *
 * Time: O(n^2 * α(n)) ≈ O(n^2)
 * Space: O(n)
 *
 * Self Note:
 * The actual row/column values don't matter here.
 * We only care whether two stones belong to the same component.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int findpar(int node, vector<int>& parent) {
        if (node == parent[node])
            return node;

        return parent[node] = findpar(parent[node], parent);
    }

    void Union(int u, int v, vector<int>& rank,
               vector<int>& parent) {

        int pu = findpar(u, parent);
        int pv = findpar(v, parent);

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();

        vector<int> rank(n, 0);
        vector<int> parent(n);

        // Initially every stone is its own component
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Connect stones having same row or same column
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {

                    Union(i, j, rank, parent);
                }
            }
        }

        // Count connected components
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (findpar(i, parent) == i)
                components++;
        }

        return n - components;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> stones = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 2},
        {2, 1},
        {2, 2}
    };

    cout << "Maximum Stones Removed: "
         << obj.removeStones(stones)
         << endl;

    return 0;
}