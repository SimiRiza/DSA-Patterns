#include <iostream>
using namespace std;
int find_fib(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    return find_fib(n-1) + find_fib(n-2);
}

int main(){
    int n = 7;
    int res = find_fib(n);
    cout<<res<<endl;
}