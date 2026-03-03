/*
Approach: Sorting + Greedy Interval Merge (Start-End Tracking)

Description:
Sort intervals. Track current start (s) and end (e).
If next interval overlaps, update end.
Else push current interval and reset.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());

        vector<vector<int>> res;
        int s = arr[0][0];
        int e = arr[0][1];

        for (auto ele : arr) {
            int curr_s = ele[0];
            int curr_e = ele[1];

            if (curr_s >= s && curr_s <= e) {
                e = max(e, curr_e);
            } else {
                res.push_back({s, e});
                s = curr_s;
                e = curr_e;
            }
        }

        res.push_back({s, e});
        return res;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> t1 = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> t2 = {{1,4},{4,5}};

    auto r1 = obj.merge(t1);
    auto r2 = obj.merge(t2);

    for(auto &v : r1){
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    cout << endl;

    for(auto &v : r2){
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    cout << endl;

    return 0;
}