#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Optimized one-pass hashmap solution.
Avoids special cases and extra loops.
Time: O(n)
Space: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // stores number -> index seen so far

        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i]; // value required to reach target

            // If required value already seen, we found the answer
            if (mp.count(need)) {
                return {mp[need], i};
            }

            // Store current value after check to avoid using same index twice
            mp[nums[i]] = i;
        }

        return {};
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    auto res1 = sol.twoSum(nums1, target1);
    cout << res1[0] << " " << res1[1] << endl;

    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    auto res2 = sol.twoSum(nums2, target2);
    cout << res2[0] << " " << res2[1] << endl;

    return 0;
}
