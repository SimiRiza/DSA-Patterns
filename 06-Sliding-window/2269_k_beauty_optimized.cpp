// Approach: Sliding Window (Digit Window of size k)
// We build the first k-length number, then slide the window by removing left digit and adding right digit.

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string num_str = to_string(num);
        int st = 0, end = 0, n = 0;

        // Build first window
        while (end < k) {
            n = n * 10 + (num_str[end] - '0');
            end++;
        }

        int count = 0;
        int base = pow(10, k - 1); // to remove leftmost digit

        while (end < num_str.length()) {
            if (n != 0 && num % n == 0) count++;

            int st_digit = num_str[st] - '0';
            int end_digit = num_str[end] - '0';

            n = (n - st_digit * base) * 10 + end_digit;

            st++;
            end++;
        }

        // Last window check
        if (n != 0 && num % n == 0) count++;

        return count;
    }
};

// ----------- main (test cases) -----------
int main() {
    Solution obj;

    cout << obj.divisorSubstrings(240, 2) << endl; // expected 2
    cout << obj.divisorSubstrings(430043, 2) << endl; // expected 2

    return 0;
}