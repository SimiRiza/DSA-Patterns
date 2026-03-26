#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Approach: Sliding Window (Front-Back Pick Simulation)

- First take k elements from the left.
- Then gradually remove elements from left and add from right.
- Track maximum sum during this transition.

Time: O(k)
Space: O(1)
*/

class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int start = 0, end = arr.size() - 1;
        int sum = 0, max_sum = 0;

        // Take first k elements from left
        while (start < k) {
            sum += arr[start];
            start++;
        }

        start--; // move back to last included index

        // Shift window: remove from left, add from right
        while (start >= 0) {
            max_sum = max(max_sum, sum);
            sum -= arr[start];
            sum += arr[end];
            start--;
            end--;
        }

        // Final check
        max_sum = max(max_sum, sum);

        return max_sum;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {11,49,100,20,86,29,72};
    int k1 = 4;
    cout << "Test 1 Output: " << sol.maxScore(test1, k1) << endl; // Expected: 232

    vector<int> test2 = {1,2,3,4,5,6,1};
    int k2 = 3;
    cout << "Test 2 Output: " << sol.maxScore(test2, k2) << endl; // Expected: 12

    return 0;
}