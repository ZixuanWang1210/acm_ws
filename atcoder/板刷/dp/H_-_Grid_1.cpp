#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
#define int long long

using namespace std;

const int maxn=1100;
const int mod=1000000007;
char mp[maxn][maxn];
int n,m;
int dp[maxn][maxn];

void sol(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    dp[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='#') continue;
            if(i==1&&j==1) continue;
            dp[i][j]=(dp[i-1][j]+dp[i][j-1]);
            dp[i][j]%=mod;
        }
    }
    cout<<dp[n][m];

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;/`    
    while(_--){
        sol();
    }

    return 0;
}
