#include<bits/stdc++.h>
using namespace std;

const int maxn=300;
int a[maxn][maxn],dp[maxn][maxn];

void sol(){
    int c,r; cin>>c>>r;
    for(int i=1;i<=c;i++){
        for(int j=1;j<=r;j++){
            cin>>a[i][j];
            dp[i][j]=max(dp[i-1][j]+a[i][j],dp[i][j-1]+a[i][j]);
        }
    }

    cout<<dp[c][r]<<endl;
}


int main(){
    int T; cin>>T;
    while(T--){
        sol();
    }

    return 0;
}