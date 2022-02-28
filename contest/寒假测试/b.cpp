#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=1e3+10;
int dp[maxn][maxn],mp[maxn][maxn];
int n,m,x,y;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>x>>y;
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=0;
            cin>>mp[i][j];
        }
    }
    
    // for(int i=0;i<=)
    dp[1][1]=mp[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1) continue;
            cout<<i-1<<' '<<j<<' '<<dp[i-1][j]<<endl;
            dp[i][j]=min(dp[i-1][j]+mp[i][j],dp[i][j-1]+mp[i][j]);
            cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
        }
    }
    
    cout<<dp[x][y]<<endl;

    return 0;
}
