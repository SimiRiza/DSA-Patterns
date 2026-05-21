#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
Approach: Stack Simulation

Description:
- Simulate a text editor using stacks
- Push normal characters into stack
- Pop when '#' (backspace) appears
- Compare final processed contents

Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/

class Solution {
public:
    bool backspaceCompare(string str1, string str2) {

        // Separate stacks to store final processed characters
        stack<char> st1;
        stack<char> st2;

        int s = 0, t = 0;

        // Process first string
        while(s != str1.length()) {

            // Normal character → add into editor
            if(str1[s] != '#') {
                st1.push(str1[s]);
            }

            // Backspace → remove previous character if possible
            else if(!st1.empty()) {
                st1.pop();
            }

            // Move to next character
            s++;
        }

        // Process second string
        while(t != str2.length()) {

            // Normal character → add into editor
            if(str2[t] != '#') {
                st2.push(str2[t]);
            }

            // Backspace → remove previous character if possible
            else if(!st2.empty()) {
                st2.pop();
            }

            // Move to next character
            t++;
        }

        // Compare final processed strings
        while(!st1.empty() && !st2.empty()) {

            // Mismatch found
            if(st1.top() != st2.top()) {
                return false;
            }

            // Remove compared characters
            st1.pop();
            st2.pop();
        }

        // Both should finish together
        return st1.empty() && st2.empty();
    }
};

int main() {

    Solution obj;

    // Final strings: "ac" and "ac"
    cout << obj.backspaceCompare("ab#c", "ad#c") << endl;

    // Final strings: "" and ""
    cout << obj.backspaceCompare("ab##", "c#d#") << endl;

    return 0;
}