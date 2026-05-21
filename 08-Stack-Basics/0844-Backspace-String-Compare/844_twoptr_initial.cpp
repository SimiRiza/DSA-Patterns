#include <iostream>
#include <string>

using namespace std;

/*
Approach: Initial Two Pointer

Description:
- Traverse strings from end
- Maintain pending deletions
- Skip invalid characters
- Compare remaining characters

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

class Solution {
public:

    bool backspaceCompare(string str1, string str2) {

        int s=str1.length()-1;
        int t=str2.length()-1;

        int popc_s=0,popc_t=0;

        while(s!=-1 || t!=-1){

            bool invalid=true;

            while(s!=-1 && invalid){

                if(str1[s]=='#'){
                    popc_s++;
                    s--;
                }

                else if(popc_s>0){
                    s--;
                    popc_s--;
                }

                else
                    invalid=false;
            }

            invalid=true;

            while(t!=-1 && invalid){

                if(str2[t]=='#'){
                    popc_t++;
                    t--;
                }

                else if(popc_t>0){
                    t--;
                    popc_t--;
                }

                else
                    invalid=false;
            }

            if(s!=-1 && t!=-1){

                if(str1[s]==str2[t]){
                    s--;
                    t--;
                }

                else
                    return false;
            }

            if(s==-1 && t!=-1 && str2[t]!='#')
                return false;

            if(t==-1 && s!=-1 && str1[s]!='#')
                return false;
        }

        return true;
    }
};

int main(){

    Solution obj;

    cout<<obj.backspaceCompare("ab#c","ad#c")<<endl;
    cout<<obj.backspaceCompare("a##c","#a#c")<<endl;

    return 0;
}