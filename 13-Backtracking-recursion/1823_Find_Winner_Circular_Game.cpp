/*
 * Problem:
 * LeetCode 1823 - Find the Winner of the Circular Game
 *
 * Approach:
 * 1. Solve the Josephus problem recursively.
 * 2. Base case:
 *      - If only one person remains, its 0-based position is 0.
 * 3. Recursively find the winner for (n - 1) people.
 * 4. Adjust the winner's position after adding the nth person:
 *      winner = (previousWinner + k) % n
 * 5. Convert the final answer from 0-based indexing to 1-based indexing.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) (recursion stack)
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int josephus(int n, int k) {
        if (n == 1)
            return 0;

        return (josephus(n - 1, k) + k) % n;
    }

    int findTheWinner(int n, int k) {
        return josephus(n, k) + 1;
    }
};

int main() {
    Solution obj;

    int n = 5;
    int k = 2;

    cout << "Winner: " << obj.findTheWinner(n, k) << endl;

    return 0;
}