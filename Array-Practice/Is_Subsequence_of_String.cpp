#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
int len_ofSubseq(string s1, string s2, int i, int j){
    if(i==s1.length() || j==s2.length()){
        return 0;
    }
    if(s1[i] == s2[j]){
        return 1 + len_ofSubseq(s1,s2,i+1,j+1);
    }
    else{
        int x = len_ofSubseq(s1,s2,i+1,j);
        return x;
    }
}
int main() {
    string s1 = "kavya";
    string s2 = "aya";
    int len = len_ofSubseq(s1,s2,0,0);
    if(len == s2.length()){
        cout<<"s2 is a subsequence of s1";
    }
    else{
        cout<<"s2 is not a subsequence of s1";
    }
        return 0;
    }
    
