#include <vector>
using namespace std;
// LeetCode 1295: Find Numbers with Even Number of Digits
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;

        // Loop through each number
        for (int num : nums) {
            int digits = 0;
            int temp = num;

            // Count digits
            while (temp > 0) {
                digits++;
                temp /= 10;
            }

            // If number of digits is even, increase count
            if (digits % 2 == 0) {
                count++;
            }
        }

        return count;
    }
};
