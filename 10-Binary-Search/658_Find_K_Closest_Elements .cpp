/*
 * LeetCode 658 - Find K Closest Elements
 * Approach: Binary Search on Window Start
 *
 * Instead of searching for individual elements, we binary search
 * the starting index of a window of size k.
 *
 * If the element just outside the right boundary is closer to x
 * than the left boundary, shift the window right.
 * Otherwise, keep the window on the left side.
 *
 * Time Complexity: O(log(n - k) + k)
 * Space Complexity: O(1) extra (excluding output)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = static_cast<int>(arr.size()) - k;

        // Binary search for the best starting index of the window
        while (left < right) {
            int mid = left + (right - left) / 2;

            // Compare distances from x
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;  // Shift window right
            } else {
                right = mid;     // Keep searching left
            }
        }

        // Return the window of size k
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> result1 = sol.findClosestElements(arr1, 4, 3);

    cout << "Test 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Test Case 2
    vector<int> arr2 = {1, 2, 3, 4, 5};
    vector<int> result2 = sol.findClosestElements(arr2, 4, -1);

    cout << "Test 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}