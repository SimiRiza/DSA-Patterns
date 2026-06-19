#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
int count_common(string s1, string s2, int i, int j){
    if(i==s1.length() || j==s2.length()){
        return 0;
    }
    if(s1[i] == s2[j]){
        return 1 + count_common(s1,s2,i+1,j+1);
    }
    else{
        int x = count_common(s1,s2,i+1,j);
        int y = count_common(s1,s2,i,j+1);
        return max(x,y);
    }
}
int main() {
    string s1 = "kavya";
    string s2 = "Sathya";
    int common = count_common(s1,s2,0,0);
    cout<<"common sequence length is "<<common;
        return 0;
    }
    
