#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

int n,m;
int s,t;
vector<int> g[11000];
bool st[11000];
int ans=0x3f3f3f3f;

void bfs(int u,int dis){
    if(u==t) {
        ans=min(ans,dis);
        return;
    }
    if(st[u]) return;
    st[u]=1;
    for(auto x:g[u]){
        if(st[x]) continue;
        bfs(x,dis+1);
    }
}

void sol(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y; cin>>x>>y;
        g[x].push_back(y),g[y].push_back(x);
    }
    cin>>s>>t;
    bfs(s,0);
    if(ans==0x3f3f3f3f) cout<<-1<<endl;
    else cout<<ans<<endl;
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
