#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    LeetCode 15 - 3Sum
    -------------------------------------------------------
    Approach:
    1. Sort the array.
    2. Fix one element (i).
    3. Use two pointers (j, k) to find pairs such that
       nums[i] + nums[j] + nums[k] == 0.
    4. Skip duplicates carefully.

    Time Complexity: O(n^2)
    Space Complexity: O(1) (excluding result storage)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate fixed elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Optimization: If current number > 0, break
            if (nums[i] > 0)
                break;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // Skip duplicates
                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return result;
    }
};

// Sample Testing
int main() {
    Solution sol;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> ans = sol.threeSum(nums);

    cout << "Triplets:\n";
    for (const auto& triplet : ans) {
        cout << "[ ";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}