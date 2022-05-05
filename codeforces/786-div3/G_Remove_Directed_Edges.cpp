#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

const int maxn=5e5+10;
int h[maxn],ne[maxn],e[maxn],idx;
int din[maxn],dout[maxn];
int dp[maxn];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u){
    if(dp[u]) return;
    dp[u]=1;
    if(dout[u]<=1) return;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        dfs(j);
        if(din[j]>=2) dp[u]=max(dp[u],dp[j]+1);
    }
}

void sol(){
    int n,m; cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        add(u,v);
        din[v]++,dout[u]++;
    }    
    for(int i=1;i<=n;i++){
        dfs(i);
    }
    cout<<*max_element(dp+1,dp+1+n)<<endl;

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
