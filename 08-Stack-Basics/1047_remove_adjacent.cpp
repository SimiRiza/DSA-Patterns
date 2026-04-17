// Approach: Stack (Remove adjacent duplicates)
// Traverse from right to left, use stack to cancel adjacent duplicates

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for(int i = s.length() - 1; i >= 0; i--) {
            if(st.empty() || st.top() != s[i]) {
                st.push(s[i]);
            }
            else {
                st.pop();
            }
        }

        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res;
    }
};

int main() {
    Solution obj;

    cout << obj.removeDuplicates("abbaca") << endl; // ca
    cout << obj.removeDuplicates("azxxzy") << endl; // ay

    return 0;
}