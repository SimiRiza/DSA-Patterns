#include <iostream>
#include <vector>
using namespace std;

/*
Approach: Sliding Window
- Maintain window sum of size k
- Check average condition for each window

Note to self:
- Can optimize by converting avg condition to: sum >= k * threshold (avoids division)
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int start = 0, end = 0, count = 0;
        long long sum = 0, avg;

        // build first window
        while (end < k) {
            sum += arr[end];
            end++;
        }

        // slide window
        while (end < arr.size()) {
            avg = sum / k;
            if (avg >= threshold)
                count++;

            sum -= arr[start];
            start++;
            sum += arr[end];
            end++;
        }

        // check last window
        avg = sum / k;
        if (avg >= threshold)
            count++;

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