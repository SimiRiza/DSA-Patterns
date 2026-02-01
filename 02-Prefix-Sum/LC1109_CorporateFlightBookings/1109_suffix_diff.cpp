#include <iostream>
#include <vector>
using namespace std;

/*
Approach:
Use a difference array with a right-to-left (suffix sum) accumulation.
For each booking [s, e, num]:
- Add num at index (e - 1) to start affecting flights to the left.
- Subtract num at index (s - 2) to stop the effect before the start.

After marking all boundaries, perform a suffix sum to build the final result.

Time Complexity:
O(m + n)
where m = number of bookings and n = number of flights.

Space Complexity:
O(n) for the difference/result array.

This is the optimized and preferred solution.
*/

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);

        // Mark boundaries
        for (auto &b : bookings) {
            int s = b[0];   // start (1-based)
            int e = b[1];   // end   (1-based)
            int num = b[2];

            ans[e - 1] += num;        // start adding from e towards left
            if (s != 1)
                ans[s - 2] -= num;    // stop adding before s
        }

        // Suffix sum (right to left)
        for (int i = n - 2; i >= 0; i--) {
            ans[i] += ans[i + 1];
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> bookings = {
        {1, 2, 10},
        {2, 3, 20},
        {2, 5, 25}
    };
    int n = 5;

    vector<int> result = sol.corpFlightBookings(bookings, n);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
