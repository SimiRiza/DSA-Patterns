/*
 * LeetCode 402 - Remove K Digits
 * Approach: Monotonic Increasing Stack + Greedy
 *
 * Idea:
 * - Maintain a monotonically increasing stack of digits.
 * - If the current digit is smaller than the stack top,
 *   remove larger digits while deletions (k) are available.
 * - If deletions remain after processing all digits,
 *   remove digits from the end of the number.
 * - Build the result from the stack, reverse it,
 *   and remove leading zeros.
 */

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;

        // Process each digit greedily
        for (char n : num) {
            int curr_dig = n - '0';

            // Remove larger previous digits to minimize the number
            while (!st.empty() && curr_dig < st.top() && k > 0) {
                st.pop();
                k--;
            }

            st.push(curr_dig);
        }

        // If deletions remain, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string res = "";

        // Build result from stack (currently reversed)
        while (!st.empty()) {
            res += (st.top() + '0');
            st.pop();
        }

        // Restore original order
        reverse(res.begin(), res.end());

        // Remove leading zeros
        int i = 0;
        while (i < (int)res.size() && res[i] == '0') {
            i++;
        }

        res = res.substr(i);

        // If all digits were removed or only zeros remain
        return res.empty() ? "0" : res;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    cout << sol.removeKdigits("1432219", 3) << endl; // Expected: 1219

    // Test Case 2
    cout << sol.removeKdigits("10200", 1) << endl;   // Expected: 200

    return 0;
}