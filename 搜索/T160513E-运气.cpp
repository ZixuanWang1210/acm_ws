#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int n, k;
long long ans;

void dfs(int dig, int num){
    if(dig==n){
        if(num%k==0) ans++;
        return;
    }
    for(int i = 1; i <= 6; i++){
        dfs(dig+1, num*10+i);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    cin >> n >> k;
    for(int i = 1; i <= 6; i++){
        dfs(1, i);
    }
    cout << ans%mod;

    return 0;
}
