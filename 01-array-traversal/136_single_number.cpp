#include <iostream>
#include <vector>
using namespace std;

/*
Approach: XOR Cancellation

Description:
Each number appears twice except one. XOR has a useful property:
a ^ a = 0 and a ^ 0 = a.

So when we XOR all numbers together, duplicate numbers cancel out,
and the remaining value is the unique number.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for (int num : nums) {
            res = res ^ num;
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {2, 2, 1};
    vector<int> test2 = {4, 1, 2, 1, 2};

    cout << "Test 1 Output: " << sol.singleNumber(test1) << endl;
    cout << "Test 2 Output: " << sol.singleNumber(test2) << endl;

    return 0;
}