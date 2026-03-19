// LC 643 - Sliding Window Maximum Average
// Approach: Fixed Size Sliding Window
// Idea: Maintain sum of window of size k, update in O(1) while sliding

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        
        long long sum = 0;
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        
        long long maxSum = sum;
        
        for(int i = k; i < n; i++){
            sum += nums[i];
            sum -= nums[i - k];
            maxSum = max(maxSum, sum);
        }
        
        return (double)maxSum / k;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,12,-5,-6,50,3};
    int k1 = 4;
    cout << "Output 1: " << sol.findMaxAverage(nums1, k1) << endl;

    vector<int> nums2 = {5};
    int k2 = 1;
    cout << "Output 2: " << sol.findMaxAverage(nums2, k2) << endl;

    return 0;
}