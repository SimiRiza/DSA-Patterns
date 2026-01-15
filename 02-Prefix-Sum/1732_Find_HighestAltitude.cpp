#include<vector>
using namespace std;
// LeetCode 1732 - Find the Highest Altitude
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int left_sum = 0;  // stores current altitude (prefix sum)
        int max = 0;       // stores maximum altitude reached

        // Traverse all altitude changes
        for (int height : gain) {
            left_sum += height;   // update current altitude
            if (left_sum > max) {
                max = left_sum;   // update max altitude
            }
        }

        // Since we start from altitude 0, max will never be negative
        return max;
    }
};
