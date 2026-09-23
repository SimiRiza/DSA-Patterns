#include <bits/stdc++.h>
using namespace std;

/*
Problem: 779. K-th Symbol in Grammar
Pattern: Recursion — Parent/Child Relationship

Approach:
- Every element in row n comes from an element in row n-1.
- If k is odd, it is the first child.
- If k is even, it is the second child.
- Recursively move to the previous row.
- 0 -> 01 and 1 -> 10.

Time: O(n)
Space: O(n) — recursion stack

Self Note:
- We do NOT generate the whole row like the brute-force approach.
- At every step, k becomes ceil(k/2), so we directly find the required symbol.
- Brute force takes O(2^n), while this recursive approach takes O(n).
*/

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1) return 0;

        int dig;

        if(k % 2 == 0) {
            dig = kthGrammar(n - 1, k / 2);
        }
        else {
            dig = kthGrammar(n - 1, (k + 1) / 2);
        }

        if(dig == 0) {
            if(k % 2 != 0) {
                return 0;
            }
            else {
                return 1;
            }
        }
        else if(dig == 1) {
            if(k % 2 != 0) {
                return 1;
            }
            else {
                return 0;
            }
        }

        return dig;
    }
};

int main() {
    Solution sol;

    int n = 4;
    int k = 5;

    cout << sol.kthGrammar(n, k) << endl;

    return 0;
}