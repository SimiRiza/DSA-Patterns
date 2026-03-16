/*
Approach: Two Pointers (Opposite Ends)

Idea:
The largest square will always come from either the leftmost negative
number or the rightmost positive number. Compare their squares and
place the larger one at the end of the result array, moving inward.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());

        int pos_ptr = nums.size() - 1;
        int res_ptr = nums.size() - 1;
        int neg_ptr = 0;

        while (neg_ptr <= pos_ptr) {
            if (nums[neg_ptr] * nums[neg_ptr] > nums[pos_ptr] * nums[pos_ptr]) {
                res[res_ptr] = nums[neg_ptr] * nums[neg_ptr];
                neg_ptr++;
                res_ptr--;
            }
            else {
                res[res_ptr] = nums[pos_ptr] * nums[pos_ptr];
                pos_ptr--;
                res_ptr--;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {-4, -1, 0, 3, 10};
    vector<int> result1 = sol.sortedSquares(test1);
    for (int x : result1) cout << x << " ";
    cout << endl;

    vector<int> test2 = {-7, -3, 2, 3, 11};
    vector<int> result2 = sol.sortedSquares(test2);
    for (int x : result2) cout << x << " ";
    cout << endl;

    return 0;
}