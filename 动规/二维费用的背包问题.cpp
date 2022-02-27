#include<bits/stdc++.h>
using namespace std;

int n,V,M;
const int maxn=1e3+10;
int dp[maxn][maxn];

int main(){
    cin>>n>>V>>M;
    for(int i=1;i<=n;i++){
        int v,m,w; cin>>v>>m>>w;
        for(int j=V;j>=v;j--){
            for(int k=M;k>=m;k--){
                dp[j][k]=max(dp[j-v][k-m]+w,dp[j][k]);
            }
        }
    }
    
    cout<<dp[V][M]<<endl;

    return 0;
}