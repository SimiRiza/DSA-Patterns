#include <vector>
#include<iostream>
using namespace std;
// LeetCode: Product of Array Except Self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        left[0]=1; right[nums.size()-1]=1;

        for(int i=1,j=nums.size()-2;i<nums.size();i++,j--){
            left[i]=left[i-1]*nums[i-1];
            right[j]=right[j+1]*nums[j+1];
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=left[i]*right[i];
        }
        return nums;
    }
    
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = sol.productExceptSelf(nums);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
