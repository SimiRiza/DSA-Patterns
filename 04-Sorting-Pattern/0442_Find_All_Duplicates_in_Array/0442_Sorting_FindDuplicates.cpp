/*
LeetCode 442 - Find All Duplicates in an Array
Approach: Sorting

Idea:
Sort the array first. Then check adjacent elements.
If two adjacent elements are equal, it is a duplicate.

Time Complexity: O(n log n)
Space Complexity: O(1) (if sorting in-place)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Check adjacent elements
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                res.push_back(nums[i]);
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
