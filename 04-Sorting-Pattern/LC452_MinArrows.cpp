/*
    LeetCode 452 - Minimum Number of Arrows to Burst Balloons

    Approach:
    - Sort intervals by starting coordinate.
    - Maintain an overlapping window [start, end].
    - If next balloon overlaps, shrink window.
    - If not, fire one arrow and reset window.

    Time Complexity: O(n log n)  (sorting)
    Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points){
        
        // Edge case: no balloons
        if(points.empty()) return 0;

        // Sort intervals lexicographically (by start, then end)
        sort(points.begin(), points.end());

        int n = points.size();
        int count = 0;

        // Initialize overlapping range
        int start = INT_MIN;
        int end = INT_MAX;

        for(auto ele : points){
            int curr_s = ele[0];
            int curr_e = ele[1];

            // If current balloon overlaps with active range
            if(curr_s >= start && curr_s <= end){
                start = max(curr_s, start);
                end   = min(curr_e, end);
            }
            else{
                // No overlap → fire one arrow
                count++;
                start = curr_s;
                end   = curr_e;
            }
        }

        // Final arrow for last overlapping group
        return count + 1;
    }
};

int main() {

    Solution obj;

    // Test Case 1
    vector<vector<int>> points1 = {{10,16},{2,8},{1,6},{7,12}};
    cout << "Minimum Arrows: "
         << obj.findMinArrowShots(points1) << endl;

    // Test Case 2
    vector<vector<int>> points2 = {{1,2},{3,4},{5,6},{7,8}};
    cout << "Minimum Arrows: "
         << obj.findMinArrowShots(points2) << endl;

    return 0;
}