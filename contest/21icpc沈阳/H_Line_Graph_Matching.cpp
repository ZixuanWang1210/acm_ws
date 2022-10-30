#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

int n,m; 
const int maxn=5e6+10;
struct node{
    int u,v,w;
    bool operator<(const node &t) const{
        return w>t.w;
    }
} seg[maxn];
int p[maxn],f[maxn];
int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}


void sol(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i,f[i]=0;
    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        seg[i]={u,v,w};
    }
    sort(seg+1,seg+1+m);
    int ans=0;
    for(int i=1;i<=m;i++){
        int u=find(seg[i].u),v=find(seg[i].v),w=seg[i].w;
        if(u==v){
            if(!f[u]) f[u]=w;
            else ans+=w+f[u],f[u]=0;
        }
        else{
            p[v]=u;
            if(!f[u]&&!f[v]) f[u]=w;
            else if(!f[u]||!f[v]) ans+=w+f[u]+f[v],f[u]=0;
            else ans+=w+max(f[u],f[v]),f[u]=min(f[u],f[v]);
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
