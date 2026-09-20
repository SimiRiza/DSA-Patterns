#include <bits/stdc++.h>
using namespace std;

/*
Problem: 779. K-th Symbol in Grammar
Pattern: Brute Force — String Generation

Approach:
- Start with "0".
- For every row:
    0 -> 01
    1 -> 10
- Generate the complete row until we reach row n.
- Return the (k-1)th character.

Time: O(2^n)
Space: O(2^n)

Self Note:
- This is a brute-force approach and will TLE for large n.
- We generate the entire row even though we only need the kth symbol.
- There is an O(n) recursive approach that directly finds the kth symbol.
*/

class Solution {
public:
    int kthGrammar(int n, int k) {
        string str = "0";

        for (int i = 1; i < n; i++) {
            string temp = str;
            str = "";

            for (char ch : temp) {
                if (ch == '0')
                    str += "01";
                else
                    str += "10";
            }
        }

        return str[k - 1] - '0';
    }
};

int main() {
    Solution sol;

    int n = 4;
    int k = 5;

    cout << sol.kthGrammar(n, k) << endl;

    return 0;
}