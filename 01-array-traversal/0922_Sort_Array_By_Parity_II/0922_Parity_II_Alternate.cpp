#include <vector>
using namespace std;

/*
Alternate Approach:
- Primarily checks odd indices.
- Swaps only when odd index has even number
  and even index has odd number.
- Still runs in O(n) time and O(1) space.
*/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even = 0, odd = 1;
        int n = nums.size();

        while (even < n && odd < n) {
            if (nums[odd] % 2 == 0) {
                if (nums[even] % 2 != 0) {
                    swap(nums[odd], nums[even]);
                } else {
                    even += 2;
                }
            } else {
                odd += 2;
            }
        }
        return nums;
    }
};
