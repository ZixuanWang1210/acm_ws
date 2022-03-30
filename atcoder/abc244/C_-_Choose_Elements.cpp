#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long 
using namespace std;

const int maxn=2e6+10;
int dp[maxn][2];
int v1[maxn],v2[maxn];

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k; cin>>n>>k;
    
    for(int i=1;i<=n;i++) cin>>v1[i];
    for(int i=1;i<=n;i++) cin>>v2[i];

    dp[1][1]=v1[1];
    dp[1][2]=v2[1];
    for(int i=2;i<=n;i++){
        if(dp[i-1][1]&&(dp[i-1][1]+k>=v1[i]&&dp[i-1][1]-k<=v1[i])) dp[i][1]=v1[i];
        if(dp[i-1][2]&&(dp[i-1][2]+k>=v1[i]&&dp[i-1][2]-k<=v1[i])) dp[i][1]=v1[i];
        if(dp[i-1][1]&&(dp[i-1][1]+k>=v2[i]&&dp[i-1][1]-k<=v2[i])) dp[i][2]=v2[i];
        if(dp[i-1][2]&&(dp[i-1][2]+k>=v2[i]&&dp[i-1][2]-k<=v2[i])) dp[i][2]=v2[i];
    }
    if(dp[n][1]||dp[n][2])cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
