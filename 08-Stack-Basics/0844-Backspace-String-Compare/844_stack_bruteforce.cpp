#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
Approach: Stack Brute Force

Description:
- Push all characters into stacks
- Process backspaces while comparing
- Simulate deletion using stack operations

Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/

class Solution {
public:
    bool backspaceCompare(string str1, string str2) {

        stack<char> s;
        stack<char> t;

        for(char s1 : str1)
            s.push(s1);

        for(char t1 : str2)
            t.push(t1);

        while(!s.empty() || !t.empty()) {

            if(!s.empty() && !t.empty() &&
               s.top()!='#' && t.top()!='#') {

                if(s.top()!=t.top())
                    return false;

                s.pop();
                t.pop();
            }

            int pop_c1=0,pop_c2=0;

            while(!s.empty() && s.top()=='#'){
                pop_c1++;
                s.pop();
            }

            while(!t.empty() && t.top()=='#'){
                pop_c2++;
                t.pop();
            }

            while(!s.empty() && pop_c1){
                if(s.top()=='#')
                    pop_c1+=2;

                s.pop();
                pop_c1--;
            }

            while(!t.empty() && pop_c2){
                if(t.top()=='#')
                    pop_c2+=2;

                t.pop();
                pop_c2--;
            }

            if(s.empty() && !t.empty() && t.top()!='#')
                return false;

            if(!s.empty() && t.empty() && s.top()!='#')
                return false;
        }

        return s.empty() && t.empty();
    }
};

int main() {

    Solution obj;

    cout<<obj.backspaceCompare("ab#c","ad#c")<<endl;
    cout<<obj.backspaceCompare("ab##","c#d#")<<endl;

    return 0;
}