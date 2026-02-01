#include <iostream>
#include <vector>
using namespace std;

/*

Time Complexity:
O(m * n) in the worst case,
where m = number of bookings and n = number of flights.

Space Complexity:
O(n) for the result array.

Note:
This approach is correct but inefficient for large inputs.
*/

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);

        for (auto seat : bookings) {
            for (int j = seat[0]; j <= seat[1]; j++) {
                res[j - 1] += seat[2]; // convert to 0-based index
            }
        }

        return res;
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
