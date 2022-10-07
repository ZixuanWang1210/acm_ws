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
vector<int> g[maxn];
struct node{
    int u,v;
} e[maxn];
int d[maxn];
int ans,st[maxn];

void sol(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        e[i]={u,v};
        d[u]++,d[v]++;
    }
    for(int i=1;i<=m;i++){
        int a=e[i].u,b=e[i].v;
        if(d[a]==d[b]){
            if(a<b) g[a].push_back(b);
            else g[b].push_back(a);
        }
        else if(d[a]>d[b]) g[a].push_back(b);
        else g[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        for(auto t:g[i]) st[t]=i;
        for(auto t:g[i]){
            for(auto tt:g[t]){
                if(st[tt]==i){
                    ans++;
                }
            }
        }
    }
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
