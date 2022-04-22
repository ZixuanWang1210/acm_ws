#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;
const int maxn=1e4+10;
int val[maxn],t[maxn];
int dp[maxn]={0};

void sol(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>t[i]>>val[i];
    }
    
    for(int i=1;i<=m;i++){
        for(int j=n;j>=t[i];j--){
            dp[j]=max(dp[j],dp[j-t[i]]+val[i]);
        }   
    }

    // for(int i=1;i<=m;i++){
    //     for(int j=1;j<=n;j++){
    //         dp[i][j]=dp[i-1][j];
    //         if(j>=t[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-t[i]]+val[i]);
    //     }
    // }
    cout<<dp[n]<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
