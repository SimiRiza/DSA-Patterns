#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int count = 0; 
        long long total_sum = 0;
        for(int num : nums){
            total_sum += num;
        }
        long long left_sum = 0;
        for(int i=0;i<nums.size()-1;i++){
            left_sum += nums[i];
            long long right_sum = total_sum - left_sum;
            if(left_sum >= right_sum){
                count++;}
        }
        return count;
    }
};

int main() {
    vector<int> nums = {10, 4, -8, 7};

    Solution sol;
    cout << sol.waysToSplitArray(nums) << endl;

    return 0;
}
