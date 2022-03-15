#include<bits/stdc++.h>
using namespace std;

int n,m;
const int maxn=1000;
int w[maxn],v[maxn],s[maxn];
int dp[maxn][maxn];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i]>>s[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=s[i];k++){
                if(j-k*v[i]>=0){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-k*v[i]]+k*w[i]);
                }
            }
        }
    }
    cout<<dp[n][m];


    return 0;
}