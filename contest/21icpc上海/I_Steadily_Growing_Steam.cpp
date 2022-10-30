#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 1e18
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

int n,m;
const int maxn=1e5+5;
int a[maxn],v[maxn],t[maxn];
int dp[105][5300][105];
int st=2600;

void sol(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>t[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=5200;j++){
            for(int k=0;k<=m;k++){
                dp[i][j][k]=-inf;
            }
        }
        dp[i][st][0]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=5200;j++){
            for(int k=0;k<=m;k++){
                dp[i][j][k]=dp[i-1][j][k];
                if(j>=t[i])dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-t[i]][k]+v[i]);
                if(j+t[i]<=5200)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j+t[i]][k]+v[i]);
 
                if(k&&j>=2*t[i])dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-2*t[i]][k-1]+v[i]);
                if(k&&j+2*t[i]<=5200)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j+2*t[i]][k-1]+v[i]);
                /*if(j>=2580&&j<=2620){
                    cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
                }*/
            }
        }
    }
    //cout<<dp[1][2601][0]<<endl;
    int ans=-inf;
    for(int i=0;i<=m;i++){
        
        ans=max(ans,dp[n][st][i]);
    }
    cout<<ans;


    // cin>>n>>k;
    // for(int i=1;i<=n;i++) cin>>v[i]>>t[i];
    // // memset(dp,-127,sizeof dp);
    //   for(int i = 0; i <= k; i ++)
    //     for(int j = 0; j <= 5200; j ++)
    //         dp[0][i][j] = -1e18;
    // dp[0][0][2600]=0;

    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=k;j++){
    //         for(int k=0;k<=5200;k++){
    //             int &x=dp[i&1][j][k];
    //             x=dp[(i&1)^1][j][k];
    //             if(k>=t[i]) x=max(x,dp[(i&1)^1][j][k-t[i]]+v[i]);
    //             if(k+t[i]<=5200) x=max(x,dp[(i&1)^1][j][k+t[i]]+v[i]);
    //             if(k+2*t[i]<=5200&&j) x=max(x,dp[(i&1)^1][j-1][k+2*t[i]]+v[i]);
    //             if(k>=2*t[i]&&j) x=max(x,dp[(i&1)^1][j-1][k-2*t[i]]+v[i]);
    //         }
    //     }
    // }
    // // cout<<dp[n&1][k][2600]<<endl;
    // int ans=-0x3f3f3f3f;
    // for(int i=1;i<=k;i++){
    //     ans=max(ans,dp[j])
    // }
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
