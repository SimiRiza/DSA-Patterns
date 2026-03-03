#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_c = 0, one_c = 0;

        // Count number of 0s and 1s
        for (int n : nums) {
            if (n == 0) zero_c++;
            if (n == 1) one_c++;
        }

        int i = 0;

        // Place all 0s
        while (zero_c) {
            nums[i] = 0;
            i++;
            zero_c--;
        }

        // Place all 1s
        while (one_c) {
            nums[i] = 1;
            i++;
            one_c--;
        }

        // Remaining positions are 2s
        while (i < nums.size()) {
            nums[i] = 2;
            i++;
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sol.sortColors(nums);

    for (int n : nums) {
        cout << n << " ";
    }

    return 0;
}
