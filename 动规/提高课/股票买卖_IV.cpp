#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

const int maxn=1e5+10;
int n,k;
int w[maxn];
int dp[maxn][1000][2];

void sol(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>w[i];

    memset(dp,-0x3f,sizeof dp);
    dp[0][0][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j][0]=dp[i-1][j][0];
            if(j) dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-1][1]+w[i]);
            dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j][0]-w[i]);
        }
    }

    int res=0;
    for(int j=0;j<=k;j++) res=max(res,dp[n][j][0]);
    cout<<res<<endl;
    return ;

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
