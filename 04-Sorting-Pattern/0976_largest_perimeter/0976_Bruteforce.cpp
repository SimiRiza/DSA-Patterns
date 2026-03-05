#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Approach: Brute Force Three-Pointer Scan

Description:
The array is first sorted. Then three indices (a, b, c) are used to check
all possible triplets where c moves from the end toward b. For each triplet,
the triangle inequality condition nums[a] + nums[b] > nums[c] is checked.
If valid, the perimeter is computed and the maximum is updated.

Time Complexity: O(n^3)
Space Complexity: O(1)
*/

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int a = 0, b = a + 1, c = n - 1;
        int curr_m = 0, m = 0;

        while (a < n - 2) {
            b = a + 1;
            while (b <= n - 1) {
                c = n - 1;
                while (c != b) {
                    if (nums[a] + nums[b] > nums[c]) {
                        curr_m = nums[a] + nums[b] + nums[c];
                        m = max(curr_m, m);
                    }
                    c--;
                }
                b++;
            }
            a++;
        }
        return m;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {2, 1, 2};
    cout << "Test 1 Output: " << sol.largestPerimeter(test1) << endl;

    vector<int> test2 = {1, 2, 1, 10};
    cout << "Test 2 Output: " << sol.largestPerimeter(test2) << endl;

    return 0;
}