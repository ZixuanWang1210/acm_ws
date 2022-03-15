#include<bits/stdc++.h>
using namespace std;

int n=4,m;
const int maxn=1010;
int v[]={0,10,20,50,100};
int dp[maxn][maxn];

int main(){
    cin>>m;

    dp[0][0]=1;
    for(int i=1;i<=4;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;v[i]*k<=j;k++){
                dp[i][j]+=dp[i-1][j-v[i]*k];
            }
        }
    }
    cout<<dp[n][m];

    return 0;
}