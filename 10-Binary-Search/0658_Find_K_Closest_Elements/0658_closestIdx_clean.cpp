#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
    LeetCode 658 - Find K Closest Elements

    Approach: Closest Index + Two Pointer Expansion

    1. Find the closest element to x using binary search.
    2. Expand left/right from that position.
    3. Always pick the closer element.
    4. Prefer the smaller value on ties.

    Time Complexity:
    - Binary Search: O(log n)
    - Expansion: O(k)
    - Total: O(log n + k)

    Space Complexity:
    - Auxiliary Space: O(1)
    - Output Space: O(k)
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int l = 0;
        int r = arr.size() - 1;

        int val = arr[0];
        int idx = 0;

        // Find index of x or closest value to x.
        while (l <= r) {
            int m = l + (r - l) / 2;

            int curDiff = abs(arr[m] - x);
            int bestDiff = abs(val - x);

            if (curDiff < bestDiff ||
                (curDiff == bestDiff && arr[m] < val)) {
                val = arr[m];
                idx = m;
            }

            if (arr[m] < x) {
                l = m + 1;
            }
            else if (arr[m] > x) {
                r = m - 1;
            }
            else {
                break;
            }
        }

        int left = idx - 1;
        int right = idx + 1;

        while (k > 1) {

            if (left < 0) {
                right++;
            }
            else if (right >= arr.size()) {
                left--;
            }
            else if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                left--;
            }
            else {
                right++;
            }

            k--;
        }

        left++;
        right--;

        vector<int> ans;

        while (left <= right) {
            ans.push_back(arr[left++]);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1, 2, 3, 4, 5};

    vector<int> ans = sol.findClosestElements(arr, 4, 3);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}