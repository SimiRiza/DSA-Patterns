/*
 Pattern: Intervals + Greedy + Sorting

    Approach:
    - Sort intervals by their starting point.
    - Keep the last merged interval in `res`.
    - If the next interval starts before or at the current
      interval's end, they overlap, so extend the end.
    - Otherwise, start a new interval.

    Time Complexity: O(n log n)
    Space Complexity: O(n)

    Self Note:
    After sorting by start time, we only need to compare the
    current interval with the LAST merged interval.

    If:
        current_start <= merged_end
    they overlap.

    Otherwise, the current interval starts a new group.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());

        int interval_idx = 1;
        int res_idx = 0;

        res.push_back(intervals[0]);

        while (interval_idx < intervals.size()) {

            int l = res[res_idx][0];
            int h = res[res_idx][1];

            int L = intervals[interval_idx][0];
            int H = intervals[interval_idx][1];

            if (L <= h) {
                res[res_idx][1] = max(h, H);
            }
            else {
                res.push_back(intervals[interval_idx]);
                res_idx++;
            }

            interval_idx++;
        }

        return res;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> intervals = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    vector<vector<int>> result = solution.merge(intervals);

    cout << "Merged intervals: ";

    for (auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    cout << endl;

    return 0;
}