#include <iostream>
#include<vector>
using namespace std;

int main(){
    int n = 7,res = 0;
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    res = dp[n-1];
    cout<<res<<endl;
}


