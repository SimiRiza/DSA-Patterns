/*
 * Problem:
 * LeetCode 151 - Reverse Words in a String
 *
 * Approach:
 * 1. Traverse the string from right to left.
 * 2. Skip extra spaces.
 * 3. Find the boundaries of each word using two pointers.
 * 4. Append each word directly to the result string.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int i = s.size() - 1;

        while (i >= 0) {
            // Skip trailing or multiple spaces
            while (i >= 0 && s[i] == ' ')
                i--;

            if (i < 0)
                break;

            int j = i;

            // Find the beginning of the current word
            while (j >= 0 && s[j] != ' ')
                j--;

            // Add a space before every word except the first one
            if (!res.empty())
                res += ' ';

            // Append the current word directly
            res += s.substr(j + 1, i - j);

            // Move to the previous word
            i = j - 1;
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
    // Reversed String: "blue is sky the"

    return 0;
}