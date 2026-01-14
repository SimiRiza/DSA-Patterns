#include <vector>
using namespace std;

// LeetCode 1013
// Partition Array Into Three Parts With Equal Sum

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        long long sum = 0;

        // Step 1: Calculate total sum of the array
        for (int num : arr) {
            sum += num;
        }

        // Step 2: If total sum is not divisible by 3, partition is impossible
        if (sum % 3 != 0) return false;

        long long target = sum / 3;
        long long left_sum = 0;
        int c = 0; // counts how many valid partitions we have found

        // Step 3: Traverse array to find first and second partitions
        for (int i = 0; i < arr.size(); i++) {
            left_sum += arr[i];

            // First partition found
            if (left_sum == target && c == 0) {
                c++;
            }
            // Second partition found (ensure space for third part)
            else if (left_sum == target * 2 && c == 1 && i < arr.size() - 1) {
                return true; // third part automatically has target sum
            }
        }

        return false;
    }
};
