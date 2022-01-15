#include<bits/stdc++.h>
using namespace std;

int n, ans;

bool isPrime(int x){
    if(x <= 2) return true;
    for(int i = 2; i <= x / i; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main(){
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(isPrime(i)) cnt ++; 
    }
   
    cnt ++;

    if(cnt <= n) cout << cnt;
    else cout << -1;

    return 0;
}