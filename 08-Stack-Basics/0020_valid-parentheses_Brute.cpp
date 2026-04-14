#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
Approach: Stack Matching

Self Note (Important ):
- Never store stack top in a variable → can become stale
- Always check: !stack.empty() before accessing top
- Rule: "No empty check = danger pop" 

Optimization Hint (refer 0020_valid-parentheses_Optimized.cpp):
- Push only opening brackets
- For closing → validate or return false immediately
- Avoid pushing invalid closing brackets → cleaner & faster
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for(char ch : s){
            if(!check.empty()){
                if(check.top() == '(' && ch==')'){
                    check.pop();
                }
                else if(check.top()  == '[' && ch==']'){
                    check.pop();
                }
                else if(check.top() == '{' && ch=='}'){
                    check.pop();
                }
                else{
                    check.push(ch);
                }
            }
            else{
                check.push(ch);
            }
        }

        if(check.empty()) return true;
        return false;
    }
};

int main() {
    Solution obj;

    string s1 = "(){}}{";
    cout << "Test 1: " << (obj.isValid(s1) ? "Valid" : "Invalid") << endl;

    string s2 = "()[]{}";
    cout << "Test 2: " << (obj.isValid(s2) ? "Valid" : "Invalid") << endl;

    return 0;
}