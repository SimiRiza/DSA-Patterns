/*
LeetCode 42 - Trapping Rain Water

Idea:
Maintain two pointers from both ends and track the maximum height seen so far
from the left and right. The side with the smaller maximum determines the
water level that can be trapped at the current position.

Time Complexity Target: O(n)
Space Complexity Target: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int n = height.size();
        int left = 0, right = n - 1;
        int res = 0;
        int left_max = height[0], ryt_max = height[n-1];
        while(left <= right){
            if(left_max <= ryt_max){
                left_max = max(height[left],left_max);
                int x = min(left_max,ryt_max) - height[left];
                res += max(0,x);
                left++;
            }
            else{
                ryt_max = max(height[right],ryt_max);
                int x = min(left_max,ryt_max) - height[right];
                res += max(0,x);
                right--;
            }

        }
        return res;

    }
};

int main() {

    Solution sol;

    vector<int> test1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Test 1: " << sol.trap(test1) << endl;
    cout << "Expected: 6" << endl << endl;

    vector<int> test2 = {4,2,0,3,2,5};
    cout << "Test 2: " << sol.trap(test2) << endl;
    cout << "Expected: 9" << endl << endl;

    vector<int> test3 = {5,0,5};
    cout << "Test 3: " << sol.trap(test3) << endl;
    cout << "Expected: 5" << endl << endl;

    vector<int> test4 = {3,0,1,3,0,5};
    cout << "Test 4: " << sol.trap(test4) << endl;
    cout << "Expected: 8" << endl << endl;

    return 0;
}