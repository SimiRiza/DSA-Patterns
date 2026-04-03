// LC: Binary Subarrays With Sum
// Approach: Sliding Window (At Most Goal Trick)
// Idea:
// Count subarrays with sum <= goal and subtract subarrays with sum <= goal-1
// exact(goal) = atMost(goal) - atMost(goal-1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    // Helper function: counts subarrays with sum <= goal
    int num_arrays(vector<int>& nums, int goal) {
        if (goal < 0) return 0;  // edge case: impossible sum

        int l = 0, r = 0, cnt = 0;
        long long sum = 0;

        while (r < nums.size()) {
            sum += nums[r];  // expand window

            // shrink window if sum exceeds goal
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }

            // count valid subarrays ending at r
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // exact = atMost(goal) - atMost(goal-1)
        return num_arrays(nums, goal) - num_arrays(nums, goal - 1);
    }
};

// -------------------- DRIVER CODE --------------------
int main() {
    Solution sol;

    vector<int> nums1 = {1,0,1,0,1};
    int goal1 = 2;
    cout << "Test 1 Output: " << sol.numSubarraysWithSum(nums1, goal1) << endl; // Expected: 4

    vector<int> nums2 = {0,0,0,0,0};
    int goal2 = 0;
    cout << "Test 2 Output: " << sol.numSubarraysWithSum(nums2, goal2) << endl; // Expected: 15

    return 0;
}