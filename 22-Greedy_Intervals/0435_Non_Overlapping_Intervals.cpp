/*
    Pattern: Greedy + Sorting

    Approach:
    - Sort intervals by their starting point.
    - Keep the current interval in `res`.
    - If the next interval overlaps with the current interval:
        - Remove one interval.
        - Keep the interval with the smaller end point.
      This gives more space for future intervals.
    - If there is no overlap, add the interval normally.

    Time Complexity: O(n log n)
    Space Complexity: O(n)

    Self Note:
    When two intervals overlap, we should NOT blindly keep
    the first interval.

    Keep the interval with the SMALLER end because it finishes
    earlier and gives us the maximum room for future intervals.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());

        res.push_back(intervals[0]);

        int interval_idx = 1;
        int res_idx = 0;
        int count = 0;

        while (interval_idx < intervals.size()) {

            int L = intervals[interval_idx][0];
            int H = intervals[interval_idx][1];

            int l = res[res_idx][0];
            int h = res[res_idx][1];

            if (L < h) {

                // Overlap: keep the interval that ends earlier.
                if (h > H) {
                    res[res_idx][0] = intervals[interval_idx][0];
                    res[res_idx][1] = intervals[interval_idx][1];
                }

                count++;
            }
            else {
                res.push_back(intervals[interval_idx]);
                res_idx++;
            }

            interval_idx++;
        }

        return count;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> intervals = {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 3}
    };

    cout << "Minimum intervals to remove: "
         << solution.eraseOverlapIntervals(intervals) << endl;

    return 0;
}