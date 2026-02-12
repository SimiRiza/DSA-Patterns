/*
LeetCode 442 - Find All Duplicates in an Array
Approach: Cyclic Sort

Idea:
Since numbers are from 1 to n, each number should be placed
at index (value - 1). After cyclic sorting, any number not
at its correct index is a duplicate.

Time Complexity: O(n)
Space Complexity: O(1) (excluding result vector)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        int n = arr.size();
        vector<int> res;

        // Step 1: Place elements at correct index using Cyclic Sort
        for (int i = 0; i < n;) {
            int correctIndex = arr[i] - 1;

            // If element is not at correct position, swap it
            if (arr[i] != arr[correctIndex]) {
                swap(arr[i], arr[correctIndex]);
            } else {
                i++;  // Move forward if already correct
            }
        }

        // Step 2: Collect elements not at correct index (duplicates)
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                res.push_back(arr[i]);
            }
        }

        return res;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {4,3,2,7,8,2,3,1};

    vector<int> ans = obj.findDuplicates(nums);

    cout << "Duplicates: ";
    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}
