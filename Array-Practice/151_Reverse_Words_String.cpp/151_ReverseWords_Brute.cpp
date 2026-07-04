/*
 * Problem:
 * LeetCode 151 - Reverse Words in a String
 *
 * Approach:
 * 1. Traverse the string from right to left.
 * 2. Build each word in reverse order.
 * 3. When a word ends, reverse it and append it to the result.
 * 4. Skip multiple spaces and avoid leading/trailing spaces in the output.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string temp = "";

        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                temp += s[i];   // Build the current word in reverse
            }
            else if (i - 1 >= 0 && s[i - 1] != ' ' && temp.length() != 0) {
                // Word completed, restore its order and append it
                reverse(temp.begin(), temp.end());
                res += temp;
                res += ' ';
                temp = "";
            }
        }

        // Append the first word of the original string
        if (temp.length() != 0) {
            reverse(temp.begin(), temp.end());
            res += temp;
        }

        return res;
    }
};

int main() {
    // Test Case
    string s = "  the sky   is blue  ";

    Solution obj;
    string ans = obj.reverseWords(s);

    cout << "Reversed String: \"" << ans << "\"" << endl;

    // Expected Output:
    // "blue is sky the"

    return 0;
}