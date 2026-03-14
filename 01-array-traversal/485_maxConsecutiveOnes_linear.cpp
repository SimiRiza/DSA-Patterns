/*
Approach: Linear Scan with Running Frequency

Idea:
Traverse the array once. 
- Maintain a counter `freq` for the current streak of 1s.
- If a 0 appears → reset the streak.
- Track the maximum streak seen using `res`.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0, res = 0, freq = 0;

        while (curr < nums.size()) {
            if (nums[curr] == 0) {
                freq = 0;
            } 
            else {
                freq++;
            }

            res = max(freq, res);
            curr++;
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {1,1,0,1,1,1};
    cout << "Test1 Output: " << sol.findMaxConsecutiveOnes(test1) << endl; // Expected: 3

    vector<int> test2 = {1,0,1,1,0,1};
    cout << "Test2 Output: " << sol.findMaxConsecutiveOnes(test2) << endl; // Expected: 2

    return 0;
}
