#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=100;
int dp[maxn][maxn][maxn];
int dis[maxn][maxn];
int n,m;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        dp[u][v][0]=1;
        dis[u][v]=1;
    }

    for(int o=1;o<=64;o++){
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dp[i][k][o-1]&&dp[k][j][o-1]){
                        dp[i][j][o]=1;
                        dis[i][j]=1;
                    }
                }
            }
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    
    cout<<dis[1][n]<<endl;
    return 0;
}
