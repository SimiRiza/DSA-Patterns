/*
    Pattern: Max Heap / Priority Queue

    Approach:
    - Calculate the squared distance of every point from the origin.
    - Store {distance, index} in a max heap.
    - Keep only k points in the heap.
    - When the heap size becomes greater than k, remove the
      farthest point because the max heap keeps the largest
      distance at the top.
    - The remaining k points are the closest points.

    Time Complexity: O(n log k)
    Space Complexity: O(k)

    Self Note:
    Use a MAX heap here because we want the farthest point
    among the current k points at the top.

    Whenever size > k:
        pop the farthest point.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < points.size(); i++) {

            int x = points[i][0];
            int y = points[i][1];

            int dist = x * x + y * y;

            pq.push({dist, i});

            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> res;

        while (!pq.empty()) {
            res.push_back(points[pq.top().second]);
            pq.pop();
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