/*
Approach: Fixed Third Element + Two Pointer Scan

Idea:
1. Sort the array.
2. Fix one element (current) as the third element of the triplet.
3. Use two pointers (start and end) to search remaining pair.
4. Move pointers depending on whether sum is smaller or larger than target.
5. Keep updating the closest sum.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int start = 0;
        int current = nums.size() - 1;
        int closest_sum = nums[0] + nums[1] + nums[nums.size()-1];

        for (int current = nums.size() - 1; current >= 0; current--) {
            
            int end = current - 1;
            start = 0;

            while (start < end) {

                int sum = nums[start] + nums[end] + nums[current];

                int difference;

                if (sum < target) {
                    difference = target - sum;
                    start++;
                }
                else {
                    difference = sum - target;
                    end--;
                }

                int current_difference = abs(sum - target);

                if (current_difference < abs(closest_sum - target)) {
                    closest_sum = sum;
                }
            }
        }

        return closest_sum;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {-1, 2, 1, -4};
    int target1 = 1;
    cout << "Test 1 Output: " << sol.threeSumClosest(nums1, target1) << endl;

    vector<int> nums2 = {0, 0, 0};
    int target2 = 1;
    cout << "Test 2 Output: " << sol.threeSumClosest(nums2, target2) << endl;

    return 0;
}