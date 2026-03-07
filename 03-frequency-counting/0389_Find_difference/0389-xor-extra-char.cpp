/*
Approach: XOR Cancellation

Idea:
Every character in string s appears in string t except one extra character.
XOR has a property: a ^ a = 0 and a ^ 0 = a.
So XOR-ing all characters from both strings cancels the common characters,
leaving only the extra character from t.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = 0;

        for(char ch : s){
            res ^= ch;   // XOR all chars of s
        }

        for(char ch : t){
            res ^= ch;   // XOR all chars of t
        }

        return res;      // remaining char is the extra one
    }
};

int main() {
    Solution sol;

    // Test case 1
    string s1 = "abcd";
    string t1 = "abcde";
    cout << sol.findTheDifference(s1, t1) << endl;

    // Test case 2
    string s2 = "";
    string t2 = "y";
    cout << sol.findTheDifference(s2, t2) << endl;

    return 0;
}