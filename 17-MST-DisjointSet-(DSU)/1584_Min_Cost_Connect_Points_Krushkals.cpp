/*
 * Approach:
 * 1. Create every possible edge using Manhattan distance.
 * 2. Put all edges in a min-heap.
 * 3. Use DSU (Disjoint Set Union) to detect cycles.
 * 4. If two points have different parents, connect them and
 *    add the edge weight.
 *
 * Time: O(E log E)
 * Space: O(E + V)
 *
 * Self Note:
 * This graph is complete, so E = V².
 * Therefore, overall time is O(V² log V).
 *
 * Kruskal → sort/pick edges + DSU to avoid cycles.
 */

#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <functional>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int find(int node, vector<int>& parent) {
        if (node == parent[node]) {
            return node;
        }

        return find(parent[node], parent);
    }

    void Union(int a, int b, vector<int>& rank,
               vector<int>& parent) {

        int parent_a = find(a, parent);
        int parent_b = find(b, parent);

        if (rank[parent_a] == rank[parent_b]) {
            rank[parent_a]++;
            parent[parent_b] = parent_a;
        }
        else if (rank[parent_a] > rank[parent_b]) {
            parent[parent_b] = parent_a;
        }
        else if (rank[parent_a] < rank[parent_b]) {
            parent[parent_a] = parent_b;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {

                int dist =
                    abs(points[i][0] - points[j][0]) +
                    abs(points[i][1] - points[j][1]);

                pq.push({dist, i, j});
            }
        }

        int wt = 0;

        vector<int> rank(points.size());
        vector<int> parent(points.size());

        for (int i = 0; i < parent.size(); i++) {
            rank[i] = 0;
            parent[i] = i;
        }

        while (!pq.empty()) {

            auto [weight, a, b] = pq.top();

            int parent_a = find(a, parent);
            int parent_b = find(b, parent);

            pq.pop();

            if (parent_a == parent_b)
                continue;

            wt += weight;
            Union(a, b, rank, parent);
        }

        return wt;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> points = {
        {0, 0},
        {2, 2},
        {3, 10},
        {5, 2},
        {7, 0}
    };

    cout << "Minimum Cost: "
         << obj.minCostConnectPoints(points)
         << endl;

    return 0;
}