#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Approach: Sliding Window

We maintain a window of size k and count number of white blocks ('W').
Goal is to find minimum whites in any window of size k.
That minimum = minimum recolors needed.
*/

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int start = 0, end = 0;
        int curr_white = 0;

        // Initial window
        while (end < k) {
            if (blocks[end] == 'W')
                curr_white++;
            end++;
        }

        int min_white = blocks.length();

        // Sliding window
        while (end < blocks.length()) {
            min_white = min(min_white, curr_white);

            if (blocks[start] == 'W')
                curr_white--;

            if (blocks[end] == 'W')
                curr_white++;

            start++;
            end++;
        }

        min_white = min(min_white, curr_white);

        return min_white;
    }
};

// Main function with test cases
int main() {
    Solution sol;

    cout << sol.minimumRecolors("WBBWWBBWBW", 7) << endl; // Expected: 3
    cout << sol.minimumRecolors("WBWBBBW", 2) << endl;    // Expected: 0

    return 0;
}