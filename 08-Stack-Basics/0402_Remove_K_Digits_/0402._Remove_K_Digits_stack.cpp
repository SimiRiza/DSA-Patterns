/*
 * LeetCode 402 - Remove K Digits
 * Approach: Monotonic Increasing Stack
 *
 * Idea:
 * - Maintain digits in increasing order using a stack.
 * - If the current digit is smaller than the stack top and we still
 *   have removals left (k), remove larger digits from the stack.
 * - If removals remain after processing all digits, remove from the end.
 * - Build the result, remove leading zeros, and handle the empty case.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<int> st;
        string res = "";
        int curr_dig;

        // Maintain a monotonic increasing stack
        for (char n : nums) {
            curr_dig = n - '0';

            while (!st.empty() && st.top() > curr_dig && k) {
                st.pop();
                k--;
            }

            st.push(curr_dig);
        }

        // Remove remaining digits from the end if needed
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        // Build result from stack (currently reversed order)
        while (!st.empty()) {
            res += (st.top() + '0');
            st.pop();
        }

        reverse(res.begin(), res.end());

        // Count leading zeros
        int zero_c = 0;
        for (int i = 0; i < (int)res.length(); i++) {
            if (res[i] == '0') {
                zero_c++;
            } else {
                break;
            }
        }

        // Remove leading zeros
        res.erase(0, zero_c);

        return res == "" ? "0" : res;
    }
};

int main() {
    Solution sol;
    cout << sol.removeKdigits("1432219", 3) << endl; // Expected: 1219
    cout << sol.removeKdigits("10200", 1) << endl;   // Expected: 200
    return 0;
}