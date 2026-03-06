#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Approach: Sorted Greedy Triangle Check

Description:
The array is sorted. Starting from the largest element as side `c`,
we check the two elements just before it (`a` and `b`).

If nums[a] + nums[b] > nums[c], the triangle inequality holds.
Since the array is sorted, this gives the maximum possible perimeter.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int m = 0;

        for(int c = n - 1; c >= 2; c--) {
            int b = c - 1;
            int a = b - 1;

            if(nums[a] + nums[b] > nums[c]) {
                m = nums[a] + nums[b] + nums[c];
                return m;
            }
        }

        return 0;
    }
};
// Self Note:
// Even if `a` starts from 0 and moves forward until
// nums[a] + nums[b] > nums[c], the perimeter calculation
// ultimately uses nums[b-1] + nums[b] + nums[c].
// Therefore, `a` can directly start at `b - 1` instead
// of iterating from the beginning.

int main() {
    Solution sol;

    vector<int> nums1 = {2,1,2};
    vector<int> nums2 = {1,2,1};
    vector<int> nums3 = {3,6,2,3};

    cout << "Test1: " << sol.largestPerimeter(nums1) << endl;
    cout << "Test2: " << sol.largestPerimeter(nums2) << endl;
    cout << "Test3: " << sol.largestPerimeter(nums3) << endl;

    return 0;
}