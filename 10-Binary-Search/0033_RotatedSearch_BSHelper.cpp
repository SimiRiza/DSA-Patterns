/*
 * LeetCode 33 - Search in Rotated Sorted Array
 * Approach: Find Sorted Half + Helper Binary Search
 *
 * Description:
 * - Determine which half is sorted.
 * - If target lies in that sorted half, use helper binary search.
 * - Otherwise, continue searching in the other half.
 *
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Standard Binary Search on a sorted range
    int BS(int s, int e, vector<int>& arr, int tar) {
        int mid;

        while (s <= e) {
            mid = s + (e - s) / 2;

            if (arr[mid] == tar)
                return mid;
            else if (arr[mid] < tar)
                s = mid + 1;
            else
                e = mid - 1;
        }

        return -1;
    }

    int search(vector<int>& arr, int tar) {
        int start = 0;
        int end = static_cast<int>(arr.size()) - 1;

        while (start <= end) {

            // Recompute middle for the current search range
            int mid = start + (end - start) / 2;

            // Left half is sorted
            if (arr[start] <= arr[mid]) {

                // Target lies inside left sorted half
                if (tar >= arr[start] && tar <= arr[mid]) {

                    if (tar == arr[start]) return start;
                    if (tar == arr[mid]) return mid;

                    return BS(start, mid, arr, tar);
                }
                else {
                    start = mid + 1;
                }
            }

            // Right half is sorted
            else {

                // Target lies inside right sorted half
                if (tar >= arr[mid] && tar <= arr[end]) {

                    if (tar == arr[start]) return start;
                    if (tar == arr[mid]) return mid;

                    return BS(mid, end, arr, tar);
                }
                else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test 1: " << sol.search(test1, 0) << endl;

    vector<int> test2 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test 2: " << sol.search(test2, 3) << endl;

    return 0;
}