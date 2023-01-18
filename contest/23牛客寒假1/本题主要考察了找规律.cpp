#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 1e24
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int double

using namespace std;

const int maxn=510;
double dp[maxn][maxn][maxn];
int n,m;

void sol(){
    cin>>n>>m; 
    
    for(int i=1;i<=n;i++){ // 前i个人
        for(int j=0;j<=m;j++){ // 共用了j个仙贝
            for(int k=0;k<=j;k++){ // 第i个人用了k个
                dp[i][j][k]=dp[i-1][j-k][k]+(k==0?0:((double)k/(double)(m-j+k)));
            }
        }
    }
    
    double res=-inf;
    for(int i=0;i<=m;i++){
        res=max(res,dp[n][m][i]);
    }
    cout<<fixed<<setprecision(12)<<res<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
