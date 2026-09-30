#include <bits/stdc++.h>
using namespace std;

/*
Pattern: Backtracking — Two Choices

Approach:
- At each alphabetic character, we have 2 choices:
    1. Make it lowercase
    2. Make it uppercase
- Digits have no choice, so we simply move ahead.
- Store the string when we reach the end.

Time: O(n * 2^n)
Space: O(n) recursion stack
       Output: O(n * 2^n)

Self Note:
- Only letters create branches.
- If there are L letters, the number of answers is 2^L.
- We modify the same string in-place instead of creating separate strings
  at every recursive call.
*/

class Solution {
public:
    void solve(int i, string &s, vector<string> &ans) {
        if(i == s.size()) {
            ans.push_back(s);
            return;
        }

        if(isalpha(s[i])) {
            // Choice 1: lowercase
            s[i] = tolower(s[i]);
            solve(i + 1, s, ans);

            // Choice 2: uppercase
            s[i] = toupper(s[i]);
            solve(i + 1, s, ans);
        }
        else {
            // Digit → no choice
            solve(i + 1, s, ans);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(0, s, ans);
        return ans;
    }
};

int main() {
    Solution sol;

    string s = "a1b2";

    vector<string> ans = sol.letterCasePermutation(s);

    for(string str : ans)
        cout << str << endl;

    return 0;
}