/*
Approach: Two Pointers (Stable Compaction)

Idea:
Traverse the array with pointer `curr`. Whenever a non-zero element is found,
place it at the next available position `correct_idx`. After all non-zero
elements are compacted at the front, fill the remaining positions with zero.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curr = 0, correct_idx = 0;

        while (curr < nums.size() && correct_idx < nums.size()) {
            if (nums[curr] != 0) {
                nums[correct_idx] = nums[curr];
                correct_idx++;
                curr++;
            } else {
                curr++;
            }
        }

        while (correct_idx < nums.size()) {
            nums[correct_idx] = 0;
            correct_idx++;
        }
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {0,1,0,3,12};
    sol.moveZeroes(test1);
    for (int x : test1) cout << x << " ";
    cout << endl;

    vector<int> test2 = {0,0,1};
    sol.moveZeroes(test2);
    for (int x : test2) cout << x << " ";
    cout << endl;

    return 0;
}
