/*
Approach: Sliding Window (size 3)
- Check every substring of length 3
- If all 3 chars are different → count++
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;

        // ensure i+2 is valid → prevents out of bounds
        for (int i = 0; i + 2 < s.length(); i++) {
            char a = s[i];
            char b = s[i + 1];
            char c = s[i + 2];

            if (a != b && b != c && a != c) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    // Test 1
    string s1 = "xyzzaz";
    cout << sol.countGoodSubstrings(s1) << endl; // expected: 1

    // Test 2
    string s2 = "aababcabc";
    cout << sol.countGoodSubstrings(s2) << endl; // expected: 4

    return 0;
}