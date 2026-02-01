#include <iostream>
#include <vector>

using namespace std;

/*
    Approach: Boyer-Moore Voting Algorithm

    Idea:
    - Maintain a current candidate and its frequency.
    - Same element increases frequency.
    - Different element decreases frequency (cancellation).
    - Majority element survives due to > n/2 occurrences.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr_major = nums[0]; // current candidate
        int freq = 1;             // strength of candidate

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == curr_major) {
                freq++;           // same element strengthens candidate
            } else {
                freq--;           // different element cancels one vote
                if (freq == 0) {
                    curr_major = nums[i]; // new candidate
                    freq = 1;
                }
            }
        }
        return curr_major;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << "Majority Element: " << sol.majorityElement(nums) << endl;
    return 0;
}
