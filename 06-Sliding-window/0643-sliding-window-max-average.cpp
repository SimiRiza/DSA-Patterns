// LC1343 - Maximum Average Subarray I
// Approach: Sliding Window
// Build first window of size k, then slide window by removing left element and adding next element.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int start = 0, end = 0;
        int sum = 0;

        // Build first window
        while (end < k) {
            sum += nums[end];
            end++;
        }

        int max_sum = sum;

        // Slide the window
        while (end < nums.size()) {
            max_sum = max(sum, max_sum);
            sum -= nums[start];
            start++;
            sum += nums[end];
            end++;
        }

        // Final check
        max_sum = max(sum, max_sum);

        return (double)max_sum / k;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,12,-5,-6,50,3};
    int k1 = 4;
    cout << "Test 1 Output: " << sol.findMaxAverage(nums1, k1) << endl;

    vector<int> nums2 = {5};
    int k2 = 1;
    cout << "Test 2 Output: " << sol.findMaxAverage(nums2, k2) << endl;

    return 0;
}