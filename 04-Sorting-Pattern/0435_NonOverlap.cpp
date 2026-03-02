// 0435_NonOverlap.cpp
// LC 435 - Non-overlapping Intervals
// Approach: Sort intervals and use start logic to count overlaps.
// Time: O(n log n)
// Space: O(1)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());

        int start = arr[0][0];
        int end = arr[0][1];
        int count = -1;

        for (auto ele : arr) {
            int curr_s = ele[0];
            int curr_e = ele[1];

            if (curr_s >= start && curr_s < end) {
                if (curr_e < end) {
                    start = curr_s;
                    end = curr_e;
                }
                count++;
            } else {
                start = curr_s;
                end = curr_e;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> test1 = {{1,2}, {2,3}, {3,4}, {1,3}};
    cout << "Test 1 Output: " << sol.eraseOverlapIntervals(test1) << endl;

    vector<vector<int>> test2 = {{1,2}, {1,2}, {1,2}};
    cout << "Test 2 Output: " << sol.eraseOverlapIntervals(test2) << endl;

    return 0;
}