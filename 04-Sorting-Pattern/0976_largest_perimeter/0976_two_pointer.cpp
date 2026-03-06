#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Approach: Sorted Two-Pointer Exploration

Description:
The array is first sorted. For each element treated as the largest side `c`,
two pointers `a` (start) and `b` (just before c) move inward.

If nums[a] + nums[b] > nums[c], triangle inequality holds.
We compute the perimeter and update the maximum.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int m = 0;

        for(int c = n - 1; c >= 2; c--) {
            int a = 0, b = c - 1;

            while(a < b) {
                if(nums[a] + nums[b] > nums[c]) {
                    m = max(m, nums[a] + nums[b] + nums[c]);
                    b--;
                    break;
                }
                else{
                    a++;
                }
            }
        }

        return m;
    }
};

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