#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Approach: Sorted Two-Pointer Exploration (Attempt toward O(n^2))

Description:
The array is sorted first. For each element treated as the largest side `c`,
two pointers `a` (left) and `b` (right before c) move inward. If the triangle
inequality nums[a] + nums[b] > nums[c] holds, we compute a candidate perimeter
and try to maximize it.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int curr_m = 0, m = 0;

        for (int c = n - 1; c >= 2; c--) {

            int a = 0;
            int b = c - 1;

            while (a < b) {

                if (nums[a] + nums[b] > nums[c]) {

                    // candidate triangle
                    curr_m = nums[a] + nums[b] + nums[c];
                    m = max(curr_m, m);

                    b--; // explore next possible pair

                } else {
                    a++; // increase sum
                }
            }
        }

        return m;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {2, 1, 2};
    cout << "Test1: " << sol.largestPerimeter(test1) << endl;

    vector<int> test2 = {3, 2, 3, 4};
    cout << "Test2: " << sol.largestPerimeter(test2) << endl;

    return 0;
}