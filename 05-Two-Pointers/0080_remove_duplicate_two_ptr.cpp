/*
Approach: Two Pointer (Allow at most two duplicates)

Idea:
Since the array is sorted, duplicates appear together.
We keep two pointers:
- curr  -> scans the array
- valid -> position to place the next allowed element

Rule:
Allow an element only if it is not equal to nums[valid-2].
This ensures at most two duplicates remain.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = 2, valid = 2;

        if (nums.size() < 2)
            return nums.size();

        while (curr < nums.size()) {
            if (nums[curr] != nums[curr - 1]) {
                nums[valid] = nums[curr];
                valid++;
                curr++;
            }
            else {
                if (nums[curr] != nums[valid - 2]) {
                    nums[valid] = nums[curr];
                    curr++;
                    valid++;
                }
                else {
                    curr++;
                }
            }
        }

        return valid;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {1,1,1,2,2,3};
    int k1 = sol.removeDuplicates(test1);
    cout << "Result length: " << k1 << "\nArray: ";
    for(int i=0;i<k1;i++) cout << test1[i] << " ";
    cout << "\n\n";

    vector<int> test2 = {0,0,1,1,1,1,2,3,3};
    int k2 = sol.removeDuplicates(test2);
    cout << "Result length: " << k2 << "\nArray: ";
    for(int i=0;i<k2;i++) cout << test2[i] << " ";
    cout << "\n";

    return 0;
}
