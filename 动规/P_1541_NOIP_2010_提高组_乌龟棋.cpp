#include<bits/stdc++.h>
using namespace std;

int n,m;
int dp[40][40][40][40];
int cnt[5];
int d[400];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }
    for(int i=1;i<=m;i++){
        int t; cin>>t;
        cnt[t]++;
    }

    dp[0][0][0][0]=d[1];
    for(int i=0;i<=cnt[1];i++){
        for(int j=0;j<=cnt[2];j++){
            for(int k=0;k<=cnt[3];k++){
                for(int l=0;l<=cnt[4];l++){
                    int dis=i*1+j*2+k*3+l*4+1,_max=-1;
                    if(i) _max=max(_max,dp[i-1][j][k][l]+d[dis]);
                    if(j) _max=max(_max,dp[i][j-1][k][l]+d[dis]);
                    if(k) _max=max(_max,dp[i][j][k-1][l]+d[dis]);
                    if(l) _max=max(_max,dp[i][j][k][l-1]+d[dis]);
                    
                    dp[i][j][k][l]=max(dp[i][j][k][l],_max);
                }
            }
        }
    }
    cout<<dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]];

    return 0;
}