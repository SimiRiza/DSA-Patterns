/*
Approach: Two Pointers

Description:
We traverse string t using a comparison pointer while tracking progress
in string s using a subsequence pointer. When characters match, we move
both pointers forward. If they do not match, we keep moving through t.
If we successfully match all characters of s, then s is a subsequence of t.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sub_ptr = 0, comp_ptr = 0;

        while (comp_ptr < t.size() && sub_ptr < s.size()) {
            char comp_char = s[sub_ptr];

            while (comp_ptr < t.size() && t[comp_ptr] != comp_char) {
                comp_ptr++;
            }

            if (comp_ptr < t.size() && t[comp_ptr] == comp_char) {
                sub_ptr++;
                comp_ptr++;
            }
        }

        if (sub_ptr == s.size() || s.size() == 0)
            return true;
        else
            return false;
    }
};

int main() {
    Solution sol;

    // Test 1
    string s1 = "abc";
    string t1 = "ahbgdc";
    cout << "Test 1: " << sol.isSubsequence(s1, t1) << endl;

    // Test 2
    string s2 = "axc";
    string t2 = "ahbgdc";
    cout << "Test 2: " << sol.isSubsequence(s2, t2) << endl;

    return 0;
}
