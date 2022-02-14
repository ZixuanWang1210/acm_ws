#include<bits/stdc++.h>
using namespace std;

const int maxn=200;
int a[maxn][maxn],dp[maxn][maxn][maxn];
int m,n;

int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }

     for(int k=2;k<=m+n;k++){
        for(int i1=1;i1<=k;i1++){
            for(int i2=1;i2<=k;i2++){
                int j1=k-i1,j2=k-i2;
                int t=a[i1][j1];
                if(i1!=i2) t+=a[i2][j2];

                int &x=dp[k][i1][i2];
                x = max(x,dp[k-1][i1-1][i2-1]+t);
                x = max(x,dp[k-1][i1-1][i2]+t);
                x = max(x,dp[k-1][i1][i2-1]+t);
                x = max(x,dp[k-1][i1][i2]+t);
            }
        }
    }
    cout<<dp[m+n][m][m]<<endl;

    return 0;
}