#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
    Approach: Frequency Count using Hash Map

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> num_count;

        // Count frequency of each element
        for (int i = 0; i < nums.size(); i++) {
            num_count[nums[i]]++;
        }

        // Find element with frequency > n/2
        for (auto it : num_count) {
            if (it.second > nums.size() / 2) {
                return it.first;
            }
        }

        return -1; // safety (LeetCode guarantees majority exists)
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << "Majority Element: " << sol.majorityElement(nums) << endl;
    return 0;
}
