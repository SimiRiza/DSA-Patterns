/*
Approach: Two Pointer Greedy

Idea:
Start with two pointers at the ends of the array. The area formed depends on the
shorter line and the width between pointers. Move the pointer pointing to the
shorter height inward in hopes of finding a taller line that may produce a larger area.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left_m = 0, right_m = height.size() - 1, area = 0;

        while(left_m <= right_m){
            area = max(area, (min(height[left_m], height[right_m]) * (right_m - left_m)));

            if(height[left_m] < height[right_m]){
                left_m++;
            }
            else{
                right_m--;
            }
        }

        return area;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {1,8,6,2,5,4,8,3,7};
    cout << "Test 1 Output: " << sol.maxArea(test1) << endl; // Expected: 49

    vector<int> test2 = {1,1};
    cout << "Test 2 Output: " << sol.maxArea(test2) << endl; // Expected: 1

    return 0;
}