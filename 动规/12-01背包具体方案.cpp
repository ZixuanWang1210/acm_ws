#include<bits/stdc++.h>
using namespace std;

const int maxn=1010;
int dp[maxn][maxn];
int n,m;
int v[maxn],w[maxn];
int cur_v;
int path[maxn],cnt;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }

    for(int i=n;i>=1;i--){
        for(int j=0;j<=m;j++){
            dp[i][j]=dp[i+1][j];
            if(j>=v[i]) dp[i][j]=max(dp[i][j],dp[i+1][j-v[i]]+w[i]);
        }
    }
    // for(int i=1;i<=n;i++){
    //     if(i==n&&cur_v>=v[i]){
    //         cout<<i<<' ';
    //         break;
    //     }
    //     if(cur_v<=0)    break;
    //     if(cur_v-v[i]>=0&&dp[i][cur_v]==dp[i+1][cur_v-v[i]]+w[i]){
    //         cout<<i<<' ';
    //         cur_v-=v[i];
    //     }
    // }
    for(int i=1,j=m;i<=n;i++){
        if(j>=v[i]&&dp[i][j]==dp[i+1][j-v[i]]+w[i]){
            path[cnt++]=i;
            j-=v[i];
        }
    }
    for(int i=0;i<cnt;i++){
        cout<<path[i]<<' ';
    }
    cout<<endl;


    return 0;
}