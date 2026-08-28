/*
 * Problem:
 * LeetCode 787 - Cheapest Flights Within K Stops
 *
 * Pattern:
 * Bellman-Ford with Limited Edges
 *
 * Approach:
 * Relax all flights k + 1 times because
 * k stops = at most k + 1 flights.
 *
 * temp = dist is IMPORTANT:
 * It stores distances from the previous round,
 * preventing multiple edges from being used in one round.
 *
 * Time: O(K * E)
 * Space: O(V)
 *
 * Self Note:
 * Classic Bellman-Ford also uses temp when each round
 * must represent exactly one more edge.
 */

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // At most k stops = at most k + 1 flights
        while (k-- + 1) {

            // Copy old distances so this round
            // doesn't use updates from the same round
            vector<int> temp = dist;

            for (int i = 0; i < flights.size(); i++) {

                int source = flights[i][0];
                int dest = flights[i][1];
                int cost = flights[i][2];

                // Make sure source is reachable
                if (temp[source] != INT_MAX &&
                    temp[source] + cost < dist[dest]) {

                    dist[dest] = temp[source] + cost;
                }
            }
        }

        if (dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};

int main() {
    Solution obj;

    int n = 4;

    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 3, 100},
        {0, 3, 500}
    };

    int src = 0;
    int dst = 3;
    int k = 2;

    cout << "Cheapest Price: "
         << obj.findCheapestPrice(n, flights, src, dst, k)
         << endl;

    return 0;
}