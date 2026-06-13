#include <iostream>
#include <vector>

using namespace std;

/*
    LeetCode 658 - Find K Closest Elements

    Approach: Binary Search on Window Start

    Instead of finding the closest element,
    directly binary search the starting position
    of the answer window of size k.

    Time Complexity:
    - Binary Search: O(log(n-k))
    - Building Answer: O(k)
    - Total: O(log(n-k) + k)

    Space Complexity:
    - Auxiliary Space: O(1)
    - Output Space: O(k)
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int left = 0;
        int right = arr.size() - k;

        while (left < right) {

            int mid = left + (right - left) / 2;

            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        return vector<int>(
            arr.begin() + left,
            arr.begin() + left + k
        );
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