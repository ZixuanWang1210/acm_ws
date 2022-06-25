#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 998244353
#define ll long long
#define int long long

using namespace std;

const int maxn=1e7+10;
int dp[maxn][3];

void sol(){
    int n; cin>>n;
    dp[1][0]=1;
    dp[1][1]=1;
    for(int i=2;i<=n;i++){
        int xx=i+1;
        int cnt1=floor((double)xx/2);
        int cnt0=ceil((double)xx/2);
        // cout<<i<<' '<<cnt0<<' '<<cnt1<<endl;
        if(i&1){
            dp[i][0]=dp[i-1][0]*((cnt0)%mod)%mod+dp[i-1][1]*cnt1%mod;
            dp[i][0]%=mod;
            dp[i][1]=dp[i-1][1]*((cnt0)%mod)%mod+dp[i-1][0]*cnt1%mod;
            dp[i][1]%=mod;
        }
        else{
            dp[i][0]=dp[i-1][0]*((xx)%mod)%mod;
            dp[i][0]%=mod;
            dp[i][1]=dp[i-1][1]*((xx)%mod)%mod;
            dp[i][1]%=mod;
        }
    }
    cout<<dp[n][1]%mod<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
