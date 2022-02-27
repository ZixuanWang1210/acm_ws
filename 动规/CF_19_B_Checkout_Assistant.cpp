#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

const int maxn=4e3+10;
ll dp[maxn][maxn];
int n;
ll t[maxn],c[maxn];

signed main(){
    cin>>n;
    ll maxt=-1;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>c[i];
        t[i]++;
        maxt=max(maxt,t[i]);
    }

    maxt+=n;
    memset(dp,127,sizeof dp);
    dp[0][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=maxt;j++){
            if(j<t[i]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=min(dp[i-1][j],dp[i-1][j-t[i]]+c[i]);
        }
    }

    ll ans=9187201950435737471;
    for(int i=n;i<=maxt;i++){
        ans=min(ans,dp[n][i]);
    }

    cout<<ans<<endl;


    return 0;
}