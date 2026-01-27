#include <vector>
using namespace std;

/*
Approach:
- Use two pointers:
  even index pointer starts at 0
  odd index pointer starts at 1
- If both indices have wrong parity, swap.
- Otherwise move the pointer that is already correct.
*/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even = 0, odd = 1;
        int n = nums.size();

        while (even < n && odd < n) {
            if (nums[even] % 2 == 0) {
                even += 2;
            } else if (nums[odd] % 2 == 1) {
                odd += 2;
            } else {
                swap(nums[even], nums[odd]);
            }
        }
        return nums;
    }
};
