#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Initial working solution using hashmap.
Explores edge cases explicitly and uses an extra pass.
Later optimized in v2.
Time: O(n)
Space: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ele_idx; // stores number -> index

        // First pass: store elements and handle self-pair case
        for (int i = 0; i < nums.size(); i++) {

            // Case when number pairs with itself (target = 2 * nums[i])
            // Ensure the same index is not reused
            if (nums[i] == target - nums[i] && ele_idx.count(nums[i])) {
                return {ele_idx[nums[i]], i};
            }

            // Store current number with its index
            ele_idx[nums[i]] = i;
        }

        // Second pass: check all remaining valid pairs
        for (auto it : ele_idx) {
            int need = target - it.first;

            // Pair exists and indices are different
            if (ele_idx.count(need) && it.second != ele_idx[need]) {
                return {it.second, ele_idx[need]};
            }
        }

        return {};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    auto res = sol.twoSum(nums, target);
    cout << res[0] << " " << res[1] << endl;

    return 0;
}
