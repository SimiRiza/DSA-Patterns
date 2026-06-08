/*
 * LeetCode 875 - Koko Eating Bananas
 * Approach: Binary Search on Answer
 *
 * We binary search the eating speed k.
 * For each speed, calculate the total hours needed to finish all piles.
 * If Koko can finish within h hours, try a smaller speed.
 * Otherwise, increase the speed.
 */

 // self-note : ceil(a / b) == (a + b - 1) / b   // for positive integers

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    // Check whether Koko can finish all bananas within h hours
    bool canEatWithinTime(int k, vector<int>& piles, int h) {
        long long time = 0;

        for (int bananas : piles) {
            // ceil(bananas / k) using integer arithmetic
            time += (bananas + k - 1) / k;

            // Early exit if already exceeding allowed hours
            if (time > h) {
                return false;
            }
        }

        return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int max_bananas = piles[0];

        // Find maximum pile size
        for (int bananas : piles) {
            if (bananas > max_bananas) {
                max_bananas = bananas;
            }
        }

        int start = 1;
        int end = max_bananas;
        int min_speed = end;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (canEatWithinTime(mid, piles, h)) {
                min_speed = min(min_speed, mid);
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return min_speed;
    }
};

int main() {
    Solution sol;

    vector<int> test1 = {3, 6, 7, 11};
    cout << "Test 1: " << sol.minEatingSpeed(test1, 8) << endl;

    vector<int> test2 = {30, 11, 23, 4, 20};
    cout << "Test 2: " << sol.minEatingSpeed(test2, 6) << endl;

    return 0;
}