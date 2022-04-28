#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;
int n,l,k;
const int maxn=1e3+10;
int dp[maxn][maxn];
int dis[maxn],t[maxn];

// void sol(){
//     cin>>n>>l>>k;
//     for(int i=1;i<=n;i++){
//         cin>>dis[i];
//         dis[i]=dis[i]-dis[i-1];
//     }
//     for(int i=1;i<=n;i++){
//         cin>>t[i];
//     }

//     memset(dp,0x3f,sizeof dp);
//     dp[0][0]=0;

//     for(int i=1;i<=n;i++){
//         for(int j=0;j<=k;j++){
//             dp[i][j]=dp[i-1][j]+dis[i]*t[i];
//             if(j>=1&&j+1<i) dp[i][j]=min(dp[i][j],dp[i-1][j-1]+)
//         }
//     }
// }

void sol(){
    int n,m,k; cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>dis[i];
    for(int i=1;i<=n;i++) cin>>t[i];

    dis[n+1]=m;

    memset(dp,0x3f,sizeof dp);

    dp[1][1]=0;
    for(int i=2;i<=n+1;i++){
        for(int j=1;j<i;j++){
            for(int p=2;p<=i;p++){
                int res=(dis[i]-dis[j])*t[j];
                dp[i][p]=min(dp[i][p],dp[j][p-1]+res);
            }
        }
    }
    int ans=1e9;
    for(int i=n-k+1;i<=n+1;i++) ans=min(ans,dp[n+1][i]);
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
