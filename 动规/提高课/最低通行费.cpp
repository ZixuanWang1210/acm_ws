#include<bits/stdc++.h>
using namespace std;

const int maxn=300;
int a[maxn][maxn],dp[maxn][maxn];

void sol(){
    int c; cin>>c;
    for(int i=0;i<=c;i++){
        for(int j=0;j<=c;j++){
            if(i==0||j==0){
                dp[i][j]=0x3f3f3f3f;
                continue;
            }
            dp[0][1]=0;
            cin>>a[i][j];
            dp[i][j]=min(dp[i-1][j]+a[i][j],dp[i][j-1]+a[i][j]);
        }
    }

    cout<<dp[c][c]<<endl;
}


int main(){
    int T; T=1;
    while(T--){
        sol();
    }

    return 0;
}