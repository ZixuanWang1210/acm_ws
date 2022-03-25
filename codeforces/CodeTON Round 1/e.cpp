#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=5e5+10;
vector<int> g[maxn];
int f[maxn];

void dfs(int u,int fa,int val){
    f[u]=g[u].size()*val;
    for(auto &x:g[u]){
        if(x==fa) continue;
        dfs(x,u,-val);
    }
}

void sol(){
    int n; cin>>n;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v),g[v].push_back(u);
    }
    // cout<<2<<endl;
    dfs(1,0,1);
    for(int i=1;i<=n;i++){
        cout<<f[i]<<' ';
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }

    

    return 0;
}
