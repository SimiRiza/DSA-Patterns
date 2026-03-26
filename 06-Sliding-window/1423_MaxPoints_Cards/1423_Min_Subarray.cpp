#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Approach: Sliding Window (Remove Minimum Subarray)

- Compute total sum.
- Find minimum sum subarray of size (n - k).
- Answer = total_sum - min_subarray_sum.

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int start = 0, end = 0, n = arr.size(), total_sum = 0;
        int curr_sum = 0, win_sum = 0, max_sum = 0;

        // Calculate total sum
        for (int num : arr) {
            total_sum += num;
        }

        // Initial window of size (n - k)
        while (end < n - k) {
            win_sum += arr[end];
            end++;
        }

        // Slide window
        while (end < n) {
            curr_sum = total_sum - win_sum;
            max_sum = max(max_sum, curr_sum);

            win_sum -= arr[start];
            win_sum += arr[end];
            start++;
            end++;
        }

        // Final check
        curr_sum = total_sum - win_sum;
        max_sum = max(max_sum, curr_sum);

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