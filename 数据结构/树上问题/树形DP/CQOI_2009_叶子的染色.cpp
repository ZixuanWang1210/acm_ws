#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;


const int maxn=1e4+10;
vector<int> g[maxn];
int n,m;
int dp[maxn][2];
int c[maxn];
int root;

void dfs(int u,int fa){
    if(u<=n) return;
    for(auto j:g[u]){
        if(j==fa) continue;
        dfs(j,u);
        dp[u][1]+=min(dp[j][1]-1,dp[j][0]);
        dp[u][0]+=min(dp[j][0]-1,dp[j][1]);
    }
}

void sol(){
    cin>>m>>n;
    root=n+1;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        // dp[i][!c[i]]=0x3f3f3f3f;
    }

    for(int i=1;i<=m-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // dp[root][1]=dp[root][0]=1;
    for(int i=1;i<=m;i++){
        dp[i][0]=dp[i][1]=1;
        if(i<=n) dp[i][!(c[i])]=0x3f3f3f3f;
    }

    dfs(root,-1);
    cout<<min(dp[root][0],dp[root][1]);

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
