// Approach: Sliding Window (Two Pointers)
// Description:
// Maintain a window [start, end] such that product of elements < k.
// Expand end, and shrink start when product >= k.
// Count all subarrays ending at 'end' as (end - start + 1).

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;

        int start = 0, end = 0, count = 0;
        long long prod = 1;

        while(end < nums.size()){
            prod *= nums[end];

            while(prod >= k){
                prod /= nums[start];
                start++;
            }

            count += (end - start + 1);
            end++;
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {10, 5, 2, 6};
    cout << sol.numSubarrayProductLessThanK(test1, 100) << endl; // Expected: 8

    vector<int> test2 = {1, 2, 3};
    cout << sol.numSubarrayProductLessThanK(test2, 0) << endl; // Expected: 0

    return 0;
}