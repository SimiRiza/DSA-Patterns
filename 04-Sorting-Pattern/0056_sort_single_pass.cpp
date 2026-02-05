#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// LC 56: Merge Intervals
// Approach: Sort + single pass merge
// Time: O(n log n), Space: O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        // Push first interval as starting reference
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            int start1 = res.back()[0];
            int end1   = res.back()[1];

            int start2 = intervals[i][0];
            int end2   = intervals[i][1];

            // Check overlap
            if (start2 <= end1) {
                // Extend the interval if needed
                if (end2 >= end1) {
                    res.back()[1] = end2;
                }
            } else {
                // No overlap, push as new interval
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> result = sol.merge(intervals);

    for (auto &interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    // Expected output: [1, 6] [8, 10] [15, 18]
    return 0;
}
