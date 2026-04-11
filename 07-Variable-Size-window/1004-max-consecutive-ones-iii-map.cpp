/*
Approach: Variable Size Sliding Window (using map)

Idea:
Maintain a window where we can flip at most k zeros to ones.
Track frequency and max frequency in current window.
Shrink when (window size - maxFreq > k).

Time: O(n)
Space: O(1)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0,end=0;
        int max_len=0,max_freq=0;
        unordered_map<int,int> freq;
        
        while(end < nums.size()){
            freq[nums[end]]++;                      // add current element
            max_freq = max(max_freq, freq[nums[end]]); // track max freq
            
            // shrink window if invalid
            while((end-start+1) - max_freq > k){
                freq[nums[start]]--;               // remove left element
                start++;
            }
            
            max_len = max(max_len, end-start+1);   // update answer
            end++;
        }
        return max_len;
    }
};

int main() {
    Solution sol;

    // Test 1
    vector<int> nums1 = {1,1,1,0,0,0,1,1,1,1,0};
    int k1 = 2;
    cout << sol.longestOnes(nums1, k1) << endl; // Expected: 6

    // Test 2
    vector<int> nums2 = {0,0,1,1,1,0,0};
    int k2 = 0;
    cout << sol.longestOnes(nums2, k2) << endl; // Expected: 3

    return 0;
}