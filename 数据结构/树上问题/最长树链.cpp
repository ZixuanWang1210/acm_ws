#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

const int maxn=1e6+10;
int a[maxn],res[maxn];
vector<int> g[maxn];

int dfs(int u,int fa,int now){
    if(now!=1) res[u]=res[fa]+1;
    else res[u]=0;

    for(auto v:g[u]){
        if(v==fa) continue;
        dfs(v,u,__gcd(now,a[v]));
    }
}

void sol(){
    int n,m; cin>>n;
    for(int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) cin>>a[i];

    dfs(1,-1,a[1]);
    int id=1;
    for(int i=1;i<=n;i++){
        if(res[i]>res[id]) id=i;
    }
    dfs(id,0,a[id]);

    int ans=1;
    for(int i=1;i<=n;i++) ans=max(ans,res[i]);
    cout<<ans<<endl;


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
