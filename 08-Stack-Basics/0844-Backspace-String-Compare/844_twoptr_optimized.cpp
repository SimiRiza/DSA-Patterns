#include <iostream>
#include <string>

using namespace std;

/*
Approach: Optimized Two Pointer

Description:
- Traverse both strings from end
- Keep track of pending deletions
- Move until next valid character
- Compare valid characters only

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

class Solution {
public:

    bool backspaceCompare(string str1,string str2){

        int s=str1.length()-1;
        int t=str2.length()-1;

        int popc_s=0,popc_t=0;

        while(s>=0 || t>=0){

            // Find next valid char in str1
            while(s>=0){

                if(str1[s]=='#'){
                    popc_s++;
                    s--;
                }

                else if(popc_s>0){
                    popc_s--;
                    s--;
                }

                else
                    break;
            }

            // Find next valid char in str2
            while(t>=0){

                if(str2[t]=='#'){
                    popc_t++;
                    t--;
                }

                else if(popc_t>0){
                    popc_t--;
                    t--;
                }

                else
                    break;
            }

            // One valid, one invalid
            if((s>=0)!=(t>=0))
                return false;

            // Compare characters
            if(s>=0 && t>=0 &&
               str1[s]!=str2[t])
                return false;

            s--;
            t--;
        }

        return true;
    }
};

int main(){

    Solution obj;

    cout<<obj.backspaceCompare("ab#c","ad#c")<<endl;
    cout<<obj.backspaceCompare("bxj##tw","bxj###tw")<<endl;

    return 0;
}