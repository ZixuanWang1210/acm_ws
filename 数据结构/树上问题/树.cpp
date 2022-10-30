#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

const int maxn=500;
int dp[maxn][maxn];
int n,k;

void sol(){
    cin>>n>>k;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j]=(dp[i-1][j]+1ll*dp[i-1][j-1]*(k-j+1)%mod)%mod;
        }
    }    
    int ans=0;
    for(int i=1;i<=k;i++){
        ans=(ans+dp[n][i])%mod;
    }
    cout<<ans<<endl;

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
