/*
Approach: Two Pointer Alternate Merge

Traverse both strings together.
Add one character from word1, then one from word2.
When one string finishes, append the remaining characters
from the other string.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int s1 = 0, s2 = 0, e1 = word1.length() - 1, e2 = word2.length() - 1;
        string res = "";

        // merge characters alternately
        while (s1 < word1.length() && s2 < word2.length()) {
            res += word1[s1];
            res += word2[s2];
            s1++;
            s2++;
        }

        // append remaining of word1
        while (s1 < word1.length()) {
            res += word1[s1];
            s1++;
        }

        // append remaining of word2
        while (s2 < word2.length()) {
            res += word2[s2];
            s2++;
        }

        return res;
    }
};

int main() {
    Solution sol;

    cout << sol.mergeAlternately("abc", "pqr") << endl;     // apbqcr
    cout << sol.mergeAlternately("ab", "pqrs") << endl;     // apbqrs

    return 0;
}