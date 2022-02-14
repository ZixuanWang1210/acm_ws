#include<bits/stdc++.h>
using namespace std;

const int maxn=20;
int a[maxn][maxn],dp[maxn][maxn][maxn];
int n;

// int dfs(int i1,int j1,int i2,int j2){
//     int t=a[i1][j1];
//     if(!i1||!j1||!i2||!j2) return 0;
//     else if(i1==i2==j1==j2==1) return a[1][1];

//     int ans=max(dfs(i1-1,j1,i2-1,j2),max(dfs(i1-1,j1,i2,j2-1),max(dfs(i1,j1-1,i2,j2-1),dfs(i1,j1-1,i2-1,j2))));
//     if(i1==i2&&j1==j2) return ans-=t;
//     else{
//         return ans;
//     }
// }

int main(){
    cin>>n;
    int r,c,k;
    while(cin>>r>>c>>k,r){
        a[r][c]=k;
    }

    for(int k=2;k<=2*n;k++){
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
    cout<<dp[n*2][n][n]<<endl;

    return 0;
}