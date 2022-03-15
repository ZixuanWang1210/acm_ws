#include<bits/stdc++.h>
using namespace std;

const int maxn=200;
int dp[maxn][maxn];
int v1[maxn],v2[maxn],w[maxn];
int m,n,k;

int main(){
    cin>>n>>m>>k;
    memset(dp,0x3f,sizeof dp);
    dp[0][0]=0;

    for(int i=1;i<=k;i++) cin>>v1[i]>>v2[i]>>w[i];

    for(int i=1;i<=k;i++){
        for(int j=n;j>=0;j--){
            for(int k=m;k>=0;k--){
                dp[j][k]=min(dp[j][k],dp[max(j-v1[i],0)][max(k-v2[i],0)]+w[i]);
            }
        }
    }

    cout<<dp[n][m];
    return 0;
}