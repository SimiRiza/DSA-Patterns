#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long sum; int n=nums.size();
        for(int s=0;s<=n-2;s++){
            sum=nums[s];
            for(int e=s+1;e<=n-1;e++){
                sum+=nums[e];
                if(sum%k==0) return true;
            }
        }
        return false;
    }
};

int main() {
    // Add test cases if needed
    return 0;
}
