#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
Approach: Stack (Opening → push, Closing → validate or fail)

- Push only opening brackets
- For closing brackets:
    → if stack empty → invalid
    → if matches top → pop
    → else → invalid
- At end: stack must be empty

Time: O(n)
Space: O(n)
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for(char ch : s){
            
            if(ch=='(' || ch=='[' || ch=='{')
                check.push(ch);
        
            else{ 
                if(check.empty()) return false;

                if( (check.top()=='(' && ch==')') || 
                    (check.top()=='{' && ch=='}') ||
                    (check.top()=='[' && ch==']')
                ) check.pop();
                else return false; 
            }
        }

        if(check.empty()) return true;
        return false;
    }
};

int main() {
    Solution obj;

    // Test case 1
    string s1 = "(){}}{";
    cout << "Test 1: " << (obj.isValid(s1) ? "Valid" : "Invalid") << endl;

    // Test case 2
    string s2 = "()[]{}";
    cout << "Test 2: " << (obj.isValid(s2) ? "Valid" : "Invalid") << endl;

    return 0;
}