#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
    LeetCode 658 - Find K Closest Elements

    Approach: Custom Binary Search + Two Pointer Expansion

    1. Use binary search to locate an element closest to x.
    2. Start a window centered around that index.
    3. Expand left/right until k elements are included.
    4. Prefer the left element when distances are equal.

    Time Complexity:
    - Binary Search: O(log n)
    - Window Expansion: O(k)
    - Total: O(log n + k)

    Space Complexity:
    - Auxiliary Space: O(1)
    - Output Array: O(k)

    Note:
    A more elegant solution exists that binary-searches the final
    window directly check file 0658_optimized_WindowSearch.cpp with O(log(n-k) + k) time complexity,
    and for cleaner code with same time complexity, check 0658_closestIdx_clean.cpp
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start = 0;
        int end = static_cast<int>(arr.size()) - 1;

        vector<int> res;

        // Binary search to locate a closest index to x.
        while (start < end) {
            int mid = start + (end - start) / 2;

            int midDist = abs(arr[mid] - x);
            int rightDist = abs(arr[mid + 1] - x);

            if (midDist < rightDist) {
                end = mid;
            }
            else if (midDist == rightDist) {

                // Special handling when adjacent values are equal.
                if (arr[mid] == arr[mid + 1]) {

                    if (x > arr[mid]) {
                        start = mid + 1;
                    }
                    else {
                        end = mid;
                    }
                }
                else {
                    // Prefer smaller value on tie.
                    end = mid;
                }
            }
            else {
                start = mid + 1;
            }
        }

        int closestIdx = start;

        int leftIdx = closestIdx - 1;
        int rightIdx = closestIdx + 1;

        // Expand around the closest element until k elements are covered.
        while (k > 1) {

            if (leftIdx < 0) {
                rightIdx++;
                k--;
            }
            else if (rightIdx >= static_cast<int>(arr.size())) {
                leftIdx--;
                k--;
            }
            else if (abs(arr[leftIdx] - x) <= abs(arr[rightIdx] - x)) {
                leftIdx--;
                k--;
            }
            else {
                rightIdx++;
                k--;
            }
        }

        leftIdx++;
        rightIdx--;

        // Collect final window.
        while (leftIdx <= rightIdx) {
            res.push_back(arr[leftIdx]);
            leftIdx++;
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> ans1 = sol.findClosestElements(arr1, 4, 3);

    cout << "Test 1: ";
    for (int x : ans1) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> arr2 = {1, 1, 2, 4, 4, 7, 9, 10, 10};
    vector<int> ans2 = sol.findClosestElements(arr2, 5, 2);

    cout << "Test 2: ";
    for (int x : ans2) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}