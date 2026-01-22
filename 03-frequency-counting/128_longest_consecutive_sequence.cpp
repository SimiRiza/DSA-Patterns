// LC 128 - Longest Consecutive Sequence
// Approach: Hash Set
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // Edge case: empty array
        if (nums.size() == 0) return 0;

        // Store all numbers for O(1) lookup
        unordered_set<int> s;
        for (int num : nums) {
            s.insert(num);
        }

        int maxLen = 1;

        // Traverse each number
        for (int num : s) {

            // Only start counting if this is the start of a sequence
            if (s.find(num - 1) == s.end()) {

                int currLen = 1;
                int x = num;

                // Extend the sequence
                while (s.find(x + 1) != s.end()) {
                    x++;
                    currLen++;
                }

                maxLen = max(maxLen, currLen);
            }
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Output: " << sol.longestConsecutive(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Output: " << sol.longestConsecutive(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {1, 100};
    cout << "Output: " << sol.longestConsecutive(nums3) << endl;

    return 0;
}
