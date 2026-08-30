/*
 * Approach:
 * 1. Initialize dist[i][j] with direct edge weights.
 * 2. Try every city as an intermediate city (via).
 * 3. Update the shortest distance between every pair:
 *      dist[i][j] = min(dist[i][j],
 *                       dist[i][via] + dist[via][j])
 * 4. Count how many cities each city can reach within the threshold.
 * 5. If counts are equal, choose the city with the larger index.
 *
 * Time: O(V^3)
 * Space: O(V^2)
 *
 * Self Note:
 * Use long long because LLONG_MAX + distance can overflow.
 * Always check for LLONG_MAX before adding.
 */

#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges,
                    int distanceThreshold) {

        vector<vector<long long>> dist(
            n, vector<long long>(n, LLONG_MAX)
        );

        for (auto arr : edges) {
            dist[arr[0]][arr[1]] = arr[2];
            dist[arr[1]][arr[0]] = arr[2];
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    if (i == j) {
                        dist[i][j] = 0;
                    }
                    else {
                        if (dist[i][via] != LLONG_MAX &&
                            dist[via][j] != LLONG_MAX)

                            dist[i][j] = min(
                                dist[i][j],
                                dist[i][via] + dist[via][j]
                            );
                    }
                }
            }
        }

        int min_count = INT_MAX;
        int ans = 0;

        for (int i = 0; i < n; i++) {

            int count = 0;

            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold)
                    count++;
            }

            if (count <= min_count) {
                ans = i;
                min_count = count;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n = 4;

    vector<vector<int>> edges = {
        {0, 1, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 1}
    };

    int distanceThreshold = 4;

    cout << "City: "
         << obj.findTheCity(n, edges, distanceThreshold)
         << endl;

    return 0;
}