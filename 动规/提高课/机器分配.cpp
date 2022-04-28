#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

const int maxn=1000;
int dp[maxn],w[maxn],fro[maxn][maxn];

void out(int x,int y){
    if(x==0) return;

    int k=fro[x][y];
    out(x-1,y-k);
    cout<<x<<' '<<k<<endl;
}

void sol(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>w[j];

        for(int j=m;j;j--){
            for(int k=1;k<=j;k++){
                int val=dp[j-k]+w[k];
                if(val>dp[j]){
                    dp[j]=val;
                    fro[i][j]=k;
                }
            }
        }
    }
    cout<<dp[m]<<endl;
    out(n,m);
    return;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
