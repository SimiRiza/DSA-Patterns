// Approach: Sliding Window + Build Number Function
// Convert number to string, use window of size k,
// build number using helper function and check divisibility.

// note to self: can optimize by building number on the fly while sliding window instead of using helper function.
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    // Helper function to build number from substring [start, end]
    int buildNumber(string &s, int start, int end) {
        int num = 0;
        for (int i = start; i <= end; i++) {
            num = num * 10 + (s[i] - '0');
        }
        return num;
    }

    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.size();

        int start = 0;
        int end = 0;
        int count = 0;

        while (end < n) {

            // expand window
            if (end - start + 1 < k) {
                end++;
            }
            else if (end - start + 1 == k) {

                int val = buildNumber(s, start, end);

                // check valid divisor
                if (val != 0 && num % val == 0) {
                    count++;
                }

                // slide window
                start++;
                end++;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    cout << sol.divisorSubstrings(240, 2) << endl;      // Output: 2
    cout << sol.divisorSubstrings(430043, 2) << endl;   // Output: 2

    return 0;
}