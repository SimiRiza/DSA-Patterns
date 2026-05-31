/*
 * LeetCode 402 - Remove K Digits
 * Approach: Monotonic Increasing String Stack
 *
 * Description:
 * - Use a string as a stack.
 * - While the current digit is smaller than the last digit in the stack
 *   and we still have removals available, remove the larger digit.
 * - This greedily builds the smallest possible number.
 * - If removals remain after processing all digits, remove digits from the end.
 * - Remove leading zeros and return "0" if the result becomes empty.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {

        string st;

        // Build a monotonic increasing stack
        for (char c : num) {

            while (!st.empty() &&
                   st.back() > c &&
                   k > 0) {

                st.pop_back();
                k--;
            }

            st.push_back(c);
        }

        // Remove remaining digits from the end if needed
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // Find first non-zero digit
        int pos = 0;
        while (pos < (int)st.size() && st[pos] == '0')
            pos++;

        // Remove leading zeros
        st.erase(0, pos);

        return st.empty() ? "0" : st;
    }
};

int main() {
    Solution sol;

    // Test 1
    cout << sol.removeKdigits("1432219", 3) << endl; // Expected: 1219

    // Test 2
    cout << sol.removeKdigits("10200", 1) << endl;   // Expected: 200

    return 0;
}