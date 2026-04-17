// LC 1544 - Make The String Great
// Approach: Stack + ASCII Difference Trick
// If two adjacent chars differ by 32 → same letter diff case → remove

#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;

        for (int i = s.length() - 1; i >= 0; i--) {
            // Optimized condition
            if (!st.empty() && abs(st.top() - s[i]) == 32) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res;
    }
};

int main() {
    Solution sol;

    // Test 1
    cout << sol.makeGood("leEeetcode") << endl; // leetcode

    // Test 2
    cout << sol.makeGood("abBAcC") << endl; // ""

    return 0;
}