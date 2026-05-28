// LC 1021 - Remove Outermost Parentheses
// Approach: Stack Simulation
//
// Idea:
// - Use stack to track current primitive parentheses depth
// - If stack already contains '(' before pushing,
//   then current '(' is not outermost -> add to result
// - Before popping ')', if stack size > 1,
//   then current ')' is not outermost -> add to result
//
// Self Note:
// This stack can actually be avoided.
// Only the current depth/count matters,
// so an integer counter is enough -> O(1) space.

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {

        stack<int> st;
        string res = "";

        for(int i = 0; i < s.length(); i++) {

            // Opening bracket
            if(s[i] == '(') {

                // If already inside a primitive,
                // then keep this bracket
                if(st.size() >= 1)
                    res += '(';

                st.push('(');
            }

            // Closing bracket
            else if(s[i] == ')') {

                // Valid matching bracket
                if(!st.empty() && st.top() == '(') {

                    // If not outermost bracket,
                    // then keep it
                    if(st.size() > 1)
                        res += ')';

                    st.pop();
                }
            }
        }

        return res;
    }
};

int main() {

    Solution obj;

    // Test 1
    string s1 = "(()())(())";
    cout << obj.removeOuterParentheses(s1) << endl;
    // Expected: ()()()

    // Test 2
    string s2 = "(()())(())(()(()))";
    cout << obj.removeOuterParentheses(s2) << endl;
    // Expected: ()()()()(())

    return 0;
}
