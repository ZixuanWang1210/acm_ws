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

const int maxn=2e5+10;
struct node{
    int u,v,w;
    bool operator<(const node &t) const{
        return w>t.w;
    }
};
node seg[maxn];
int p[maxn];
int a[maxn],cnt;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
int n,m,q;

int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

void kruskal(){
    sort(seg+1,seg+1+m);
    for(int i=1;i<=m;i++){
        int u=find(seg[i].u),v=find(seg[i].v),w=seg[i].w;
        if(u!=v){
            a[++cnt]=a[u]+a[v];
            p[u]=p[v]=p[cnt]=cnt;
            
        }
    }
}

void sol(){
    cin>>n>>m>>q;
    for(int i=1;i<=2*n+2;i++) p[i]=i;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++){
        cin>>seg[i].u>>seg[i].v>>seg[i].w;
    }
    kruskal();

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
