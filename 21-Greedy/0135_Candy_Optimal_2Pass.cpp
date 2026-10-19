#include <bits/stdc++.h>
using namespace std;

/*
Problem: LeetCode 135 - Candy
Pattern: Greedy - Two Pass

Approach:
- Give every child 1 candy initially.
- Right to left:
    If rating[curr] > rating[curr + 1],
    curr needs more candies than the child on the right.
- Left to right:
    If rating[curr] > rating[curr - 1],
    curr needs more candies than the child on the left.
- Take the maximum requirement from both directions.

Time: O(n)
Space: O(n)

Self Note:
One pass cannot properly handle both sides of a child.

So:
    Right → Left handles decreasing sequences.
    Left → Right handles increasing sequences.

The condition <= is important because a child may already
have more candies from the opposite pass.

*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> choc(n, 1);

        // Right to Left
        for(int curr = n - 2; curr >= 0; curr--) {
            if(ratings[curr] > ratings[curr + 1] &&
               choc[curr] <= choc[curr + 1]) {

                choc[curr] = choc[curr + 1] + 1;
            }
        }

        // Left to Right
        for(int curr = 1; curr <= n - 1; curr++) {
            if(ratings[curr] > ratings[curr - 1] &&
               choc[curr] <= choc[curr - 1]) {

                choc[curr] = choc[curr - 1] + 1;
            }
        }

        int sum = 0;

        for(int c : choc) {
            sum += c;
        }

        return sum;
    }
};

int main() {
    Solution sol;

    vector<int> ratings = {1, 0, 2};

    cout << sol.candy(ratings) << endl;

    return 0;
}