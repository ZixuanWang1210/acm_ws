#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
#define int long long
const int maxn=1e7+10;
int n;
int dp[maxn];


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]+=(dp[i-3]*2)%mod;
        dp[i]%=mod;
        dp[i]+=(dp[i-2]*2)%mod;
        dp[i]%=mod;
        dp[i]+=(dp[i-1]+1)%mod;
        dp[i]%=mod;
        // dp[i]=dp[i-3]*2+dp[i-2]*2+dp[i-1]+1;
    }
    dp[n]%=mod;
    cout<<dp[n];
    

    return 0;
}