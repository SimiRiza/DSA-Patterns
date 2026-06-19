#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
string count_common(string s1, string s2, int i, int j){
    if(i==s1.length() || j==s2.length()){
        return ""; // empty string
    }
    if(s1[i] == s2[j]){
        return s1[i] + count_common(s1,s2,i+1,j+1);
    }
    else{
        string x = count_common(s1,s2,i+1,j);
        string y = count_common(s1,s2,i,j+1);
        return x.length() >= y.length() ? x : y;
    }
}
int main() {
    string s1 = "kavya";
    string s2 = "Sathya";
    string common = count_common(s1,s2,0,0);
    cout<<"common sequence is "<<common;
        return 0;
    }
    
