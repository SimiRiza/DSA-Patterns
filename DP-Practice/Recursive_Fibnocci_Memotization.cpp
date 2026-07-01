#include <iostream>
#include<vector>
using namespace std;
int find_fib(int n, vector<int> &dp){
    
    if(n==1) return 0;
    if(n==2) return 1;
    if(dp[n-1] != -1) return dp[n-1];
    return find_fib(n-1,dp) + find_fib(n-2,dp);
}

int main(){
    int n = 7;
    vector<int> dp(n+1, -1);
    int res = find_fib(n,dp);
    cout<<res<<endl;
}