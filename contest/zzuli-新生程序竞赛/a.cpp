#include<bits/stdc++.h>
#define int long long
using namespace std;

const int P=1000000007;

void sol(){
    int n,k; cin>>n>>k;
    vector<int> dp(2*n);
    for(int i=1;i<=k;i++){
        int t; cin>>t;
        dp[t]=-0x3f3f3f3f;
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        if(dp[i]==-0x3f3f3f3f) continue;
        if(dp[i-1]!=-0x3f3f3f3f) dp[i]+=dp[i-1],dp[i]%=P;
        if(dp[i-2]!=-0x3f3f3f3f&&i-2>=0)  dp[i]+=dp[i-2],dp[i]%=P;
    }
    if(dp[n]<0) cout<<0<<endl;
    else cout<<dp[n]<<endl;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}