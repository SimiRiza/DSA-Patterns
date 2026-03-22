// Approach: Sliding Window with Running Sum
// Idea: Maintain a window [start, end] where we try to make all elements equal to nums[end]
// by checking if total increments needed <= k using prefix-like running sum.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int start = 0, end = 1;
        int ans = 1;

        // Edge case: single element
        if (nums.size() == 1) return 1;

        long long run_sum = (long long)nums[start] + nums[end];

        while (end < nums.size()) {
            long long tar_sum = (long long)(end - start + 1) * nums[end];

            if (k >= (tar_sum - run_sum)) {
                ans = max(ans, (end - start + 1));

                if (end != nums.size() - 1) {
                    end++;
                    run_sum += nums[end];
                } else {
                    end++;
                }
            } else {
                run_sum -= nums[start];
                start++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {1, 2, 4};
    int k1 = 5;
    cout << "Test 1 Output: " << sol.maxFrequency(test1, k1) << endl; // Expected: 3

    vector<int> test2 = {1, 4, 8, 13};
    int k2 = 5;
    cout << "Test 2 Output: " << sol.maxFrequency(test2, k2) << endl; // Expected: 2

    return 0;
}