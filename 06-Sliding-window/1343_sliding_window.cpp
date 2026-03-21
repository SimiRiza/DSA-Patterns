#include <iostream>
#include <vector>
using namespace std;

/*
Approach: Sliding Window
- Convert avg condition to sum >= k * threshold
- Maintain window sum of size k
- Slide window and count valid subarrays
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int target = k * threshold;
        
        int sum = 0;
        
        // first window
        for(int i = 0; i < k; i++) {
            sum += arr[i];
        }
        
        int count = 0;
        if(sum >= target) count++;
        
        // sliding window
        for(int i = k; i < n; i++) {
            sum += arr[i];
            sum -= arr[i - k];
            
            if(sum >= target) count++;
        }
        
        return count;
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {2,2,2,2,5,5,5,8};
    int k1 = 3, threshold1 = 4;
    cout << sol.numOfSubarrays(arr1, k1, threshold1) << endl; // 3

    vector<int> arr2 = {1,1,1,1,1};
    int k2 = 1, threshold2 = 0;
    cout << sol.numOfSubarrays(arr2, k2, threshold2) << endl; // 5

    return 0;
}