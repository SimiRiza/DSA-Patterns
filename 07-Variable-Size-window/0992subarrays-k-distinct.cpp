// LeetCode 992 - Subarrays with K Different Integers
// Approach: Sliding Window + AtMost(K) trick
// Count subarrays with at most K distinct, then subtract at most (K-1)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    int atmostK_unique(vector<int>& nums, int k){
        int start = 0, end = 0, count = 0;
        unordered_map<int,int> freq;

        while(end < nums.size()){
            freq[nums[end]]++;

            // shrink window if more than k distinct
            while(freq.size() > k){
                freq[nums[start]]--;
                if(freq[nums[start]] == 0)
                    freq.erase(nums[start]);
                start++;
            }

            // count subarrays ending at 'end'
            count += (end - start + 1);
            end++;
        }
        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostK_unique(nums, k) - atmostK_unique(nums, k - 1);
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,2,1,2,3};
    int k1 = 2;
    cout << "Test 1 Output: " << sol.subarraysWithKDistinct(nums1, k1) << endl; // Expected: 7

    vector<int> nums2 = {1,2,1,3,4};
    int k2 = 3;
    cout << "Test 2 Output: " << sol.subarraysWithKDistinct(nums2, k2) << endl; // Expected: 3

    return 0;
}