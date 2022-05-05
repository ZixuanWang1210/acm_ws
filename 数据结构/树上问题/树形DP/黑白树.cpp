// case 1: 此节点能被已染色的子节点覆盖 这时只要更新理论最大覆盖范围
// case 2: 此节点不能被已染色的子节点覆盖 选择那个提供最大覆盖范围的子节点染
#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

const int maxn=1e6;
int h[maxn],ne[maxn],e[maxn],idx;
int n,ans;
int k[maxn],dp[maxn],a[maxn];

void dfs(int u,int fa){
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,u);
        a[u]=max(a[u],a[j]-1);
        dp[u]=max(dp[u],dp[j]-1);
    }
    if(!dp[u]){
        ans++;
        dp[u]=a[u];
    }
}

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void sol(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=2;i<=n;i++){
        int u; cin>>u;
        add(u,i);
    }

    for(int i=1;i<=n;i++) cin>>a[i];

    dfs(1,0);
    cout<<ans<<endl;

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
