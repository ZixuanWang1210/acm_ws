#include<bits/stdc++.h>
using namespace std;

const int N=210,M=N*N/2;
int dp[N][N];
bool vis[N];
int n,m,Q,t[N];

int main(){
    memset(dp,0x3f,sizeof dp);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>t[i],dp[i][i]=0;

    int u,v,w;
    for(int i=1;i<=m;i++) cin>>u>>v>>w,dp[u][v]=dp[v][u]=w;
    cin>>Q;
    int now=0;
    while(Q--){
        cin>>u>>v>>w;
        // memset(dp,0x3f,sizeof dp);
        // for(int k=now;k<w&&t[k]<=w;k++,now++){
        //     // cout<<"now"<<now<<endl;
        //     for(int i=0;i<n;i++){
        //         for(int j=0;j<n;j++){
        //             if(dp[i][j]>dp[i][k]+dp[k][j]){
        //                 dp[i][j]=dp[i][k]+dp[k][j];
        //             }
        //         }
        //     }
        // }
        for(int k=0;k<n;k++){
            if(t[k]<=w&&!vis[k]){
                vis[k]=1;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(dp[i][j]>dp[i][k]+dp[k][j])
                            dp[i][j]=dp[i][k]+dp[k][j];
                    }
                }
            }
        }
        if(t[u]<=w&&t[v]<=w&&dp[u][v]<0x3f3f3f3f) cout<<dp[u][v]<<endl;
        else cout<<-1<<endl;
    }

    return 0;
}