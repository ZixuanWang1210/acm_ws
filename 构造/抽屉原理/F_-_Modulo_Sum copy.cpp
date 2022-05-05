#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

bool dp[1005][1005];

void sol(){
    int n,m; cin>>n>>m;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i],v[i]%=m;

    if(n>m){
        cout<<"YES"<<endl;
        return ;
    }

    for(int i=1;i<=n;i++){
        dp[i][v[i]]=true;
        for(int j=0;j<m;j++){
            dp[i][j]|=dp[i-1][j];
            if(dp[i-1][j]) dp[i][(j+v[i])%m]=true;
        }
    }

    if(dp[n][0]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    // cin>>_; 
    while(_--){
        sol();
    }

    return 0;
}
