/*
 * LeetCode 2300 - Successful Pairs of Spells and Potions
 * Approach: Sort + Binary Search
 *
 * Sort the potions array once.
 * For each spell, binary search for the first potion whose
 * product with the spell is >= success.
 *
 * Time Complexity: O(m log m + n log m)
 * Space Complexity: O(1) extra (excluding output array)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells,
                                vector<int>& potions,
                                long long success) {

        // Sort potions for binary search
        sort(potions.begin(), potions.end());

        int n = potions.size();
        vector<int> count;

        for (int spell : spells) {

            int start = 0;
            int end = n - 1;

            // Stores first valid index, n means "not found"
            int ans = n;

            while (start <= end) {
                int mid = start + (end - start) / 2;

                // Force multiplication in long long to avoid overflow
                long long power = 1LL * spell * potions[mid];

                if (power >= success) {
                    ans = mid;       // Possible answer
                    end = mid - 1;   // Search further left
                } else {
                    start = mid + 1; // Need larger potion
                }
            }

            // Number of valid potions from ans to n-1
            count.push_back(n - ans);
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<int> spells1 = {5, 1, 3};
    vector<int> potions1 = {1, 2, 3, 4, 5};
    long long success1 = 7;

    vector<int> result1 =
        sol.successfulPairs(spells1, potions1, success1);

    cout << "Test 1: ";
    for (int x : result1) {
        cout << x << " ";
    }
    cout << "\n";

    vector<int> spells2 = {3, 1, 2};
    vector<int> potions2 = {8, 5, 8};
    long long success2 = 16;

    vector<int> result2 =
        sol.successfulPairs(spells2, potions2, success2);

    cout << "Test 2: ";
    for (int x : result2) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}