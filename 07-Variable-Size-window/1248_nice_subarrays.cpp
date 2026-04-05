// LC 1248 - Count Number of Nice Subarrays
// Approach: Sliding Window + AtMost Trick

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int sub_arrays_lessthan_k(vector<int>& nums, int k){
        int left =0,right=0,odd_c=0,odd_lessK=0;

        while(right < nums.size()){
            if(nums[right]%2!=0) // if odd, increase count
                odd_c++;

            while(odd_c > k && left<nums.size()){ // shrink if exceeded k
                if(nums[left]%2!=0)
                    odd_c--;
                left++;
            }

            odd_lessK += (right-left+1); // count valid subarrays ending at right
            right++;
        }
        return odd_lessK;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return sub_arrays_lessthan_k(nums,k) - sub_arrays_lessthan_k(nums,k-1); // exact k = atMost(k) - atMost(k-1)
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,1,2,1,1};
    int k1 = 3;
    cout << "Test 1 Output: " << sol.numberOfSubarrays(nums1, k1) << endl;

    vector<int> nums2 = {2,4,6};
    int k2 = 1;
    cout << "Test 2 Output: " << sol.numberOfSubarrays(nums2, k2) << endl;

    return 0;
}