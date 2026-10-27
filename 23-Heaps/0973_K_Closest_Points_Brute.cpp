/*
    Pattern: Greedy + Sorting

    Approach:
    - Calculate the squared distance of every point from the origin.
    - Copy the distances into a helper vector and sort it.
    - The kth smallest distance becomes the maximum allowed distance.
    - Add every point whose distance is <= this maximum.
    - The problem guarantees that the answer is unique, so this
      gives exactly k points.

    Time Complexity: O(n log n)
    Space Complexity: O(n)

    Self Note:
    The kth smallest distance acts as the boundary for selecting
    the k closest points.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<int> dist;
        vector<int> helper;
        int i = 0;

        for (auto point : points) {
            int x = point[0];
            int y = point[1];

            dist.push_back(x * x + y * y);
        }

        helper = dist;

        sort(helper.begin(), helper.end());

        int maximum = helper[k - 1];

        vector<vector<int>> res;

        for (int i = 0; i < dist.size(); i++) {
            if (dist[i] <= maximum) {
                res.push_back(points[i]);
            }
        }

        return res;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> points = {
        {1, 3},
        {-2, 2},
        {5, 8},
        {0, 1}
    };

    int k = 2;

    vector<vector<int>> result = solution.kClosest(points, k);

    cout << "K closest points: ";

    for (auto point : result) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }

    cout << endl;

    return 0;
}