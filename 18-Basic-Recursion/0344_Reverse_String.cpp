#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Swap the first and last characters.
- Move start forward and end backward.
- Repeat until start >= end.

Time: O(n)
Space: O(n) — recursion stack

Self Note:
- The swap + two-pointer idea is the same as iterative reversal.
- Recursion only adds O(n) stack space.
*/

class Solution {
public:
    void reverseString_helper(vector<char>& s, int start, int end) {
        if(start >= end)
            return;

        swap(s[start], s[end]);

        reverseString_helper(s, start + 1, end - 1);
    }

    void reverseString(vector<char>& s) {
        reverseString_helper(s, 0, s.size() - 1);
    }
};

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    Solution sol;
    sol.reverseString(s);

    for(char c : s)
        cout << c;

    return 0;
}