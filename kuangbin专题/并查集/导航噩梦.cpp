#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define pii pair<int,int> 
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

int n,m;
const int maxn=1e5+10;
int p[maxn];
pii mp[maxn];
bool st[maxn]={false};
int q;
int disx[maxn],disy[maxn];
int ans[maxn];

struct node{
    int u,v,dis;
    char dec;
} seg[maxn];

struct N1{
    int a,b,i,id;
    bool operator<(const N1 &t) const {
        return i<t.i;
    }
} ask[maxn];

int find(int x){
    if(x==p[x]) return x;
    int root=find(p[x]);
    disx[x]+=disx[p[x]];
    disy[x]+=disy[p[x]];
    p[x]=root;
    return p[x];
}


void merge(node s){
    int u=s.u,v=s.v;
    int op=0;
    if(s.dec=='S'||s.dec=='E') op=1;
    else op=-1;
    int pu=find(u),pv=find(v);
    if(s.dec=='S'||s.dec=='N'){
        if(pu!=pv){
            p[pu]=pv;
            disx[pu]=disx[v]-disx[u]+s.dis*op;
            disy[pu]=disy[v]-disy[u];
        }
    }
    else{
        if(pu!=pv){
            p[pu]=pv;
            disy[pu]=disy[v]-disy[u]+s.dis*op;
            disx[pu]=disx[v]-disx[u];
        }
    }
    return;
}

void sol(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1;i<=m;i++){
        cin>>seg[i].u>>seg[i].v>>seg[i].dis>>seg[i].dec;
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>ask[i].a>>ask[i].b>>ask[i].i;
        ask[i].id=i;
    }
    sort(ask+1,ask+1+q);
    int idx=1;
    for(int i=1;i<=q;i++){
        // cout<<ask[i].i<<endl;
        int to=ask[i].i;
        int id=ask[i].id;
        bool bz=false;
        while(idx<=to) merge(seg[idx++]),bz=true;
        if(bz) idx--;
        int a=ask[i].a,b=ask[i].b;
        int pa=find(a),pb=find(b);
        // cout<<pa<<' '<<pb<<endl;
        if(pa!=pb) ans[id]=-1;
        else{
            int tmp=abs(disx[a]-disx[b])+abs(disy[a]-disy[b]);
            // cout<<tmp<<endl;
            ans[id]=tmp;
        }
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<endl;

}

signed main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
