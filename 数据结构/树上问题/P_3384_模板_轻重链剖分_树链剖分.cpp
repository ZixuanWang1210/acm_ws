#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define LL long long
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long
using namespace std;

const int maxn=500005;
//son该节点的重儿子编号
//id对树重新标号的新编号，top[x] x所在链的链头节点的编号
int dep[maxn],pa[maxn],siz[maxn],son[maxn];
int id[maxn],top[maxn],val[maxn];
int cnt;

int n,m,r,p,mod;
int c[maxn];

int h[maxn],ne[maxn],e[maxn],w[maxn],idx;

struct segT{
    int l,r;
    long long sum,flag;
} tr[maxn<<3];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs1(int u,int fa){
    pa[u]=fa;
    siz[u]=1;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs1(j,u);
        dep[j]=dep[u]+1;
        siz[u]+=siz[j];
        if(siz[j]>siz[son[u]]){
            son[u]=j;
        }
    }
}

void dfs2(int u,int tp){
    id[u]=++cnt;
    val[cnt]=c[u];
    top[u]=tp;
    if(!son[u]) return;
    dfs2(son[u],tp);
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j!=son[u]&&j!=pa[u])
            dfs2(j,j);
    }
}

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    tr[u].sum%=mod;
}

void pushdown(int u)
{
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.flag)
    {
        left.sum += (root.flag * (left.r - left.l + 1))%mod;
        left.sum%=mod;
        left.flag += root.flag;
        // left.flag%=mod;
        right.sum += (root.flag * (right.r - right.l + 1))%mod;
        left.sum%=mod;
        right.flag += root.flag;
        // right.flag%=mod;
        root.flag = 0;
    }
}

void build(int u, int l, int r)
{
    tr[u] = {l, r, val[r], 0};
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void update(int u, int l, int r, int k)
{
    if (l <= tr[u].l && r >= tr[u].r)
    {
        tr[u].flag += k;
        // tr[u].flag%=mod;
        tr[u].sum += (k * (tr[u].r - tr[u].l + 1))%mod;
        tr[u].sum%=mod;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) update(u << 1, l, r, k);
    if (r > mid) update(u << 1 | 1, l, r, k);
    pushup(u);
}

LL query(int u, int l, int r)
{
    if (l <= tr[u].l && r >= tr[u].r) return tr[u].sum;
    pushdown(u);
    // int tot=tr[u].flag*(min(tr[u].r,r)-max(tr[u].l,l)+1)%p;
    int mid = tr[u].l + tr[u].r >> 1;
    LL res = 0;
    // if(l>mid) return query(u<<1|1,l,r)%mod;
    // else if(r<=mid) return query(u<<1,l,r)%mod;
    // else return (query(2*u,l,mid)+query(2*u+1,mid+1,r))%mod;
    if (l <= mid) res =(res+ query(u << 1, l, r))%mod;
    if (r > mid) res =(res+ query(u << 1 | 1, l, r))%mod;
    return res%mod;
}



LL query_path(int x,int y){
    LL ans=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ans=(ans+query(1,id[top[x]],id[x]))%mod;
        x=pa[top[x]];
    }
    // cout<<id[x]<<' '<<id[y]<<endl;
    if(dep[x]>dep[y]) swap(x,y);
    // cout<<query(1,id[x],id[y])<<endl;
    ans=(ans+query(1,id[x],id[y]))%mod; 
    return ans;
}

void update_path(int x,int y,int v){
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        update(1,id[top[x]],id[x],v);
        x=pa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    update(1,id[x],id[y],v);
}

LL query_tree(int u){
    return query(1,id[u],id[u]+siz[u]-1);
}

void update_tree(int u,int k){
    update(1,id[u],id[u]+siz[u]-1,k);
}


signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>r>>mod;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++) cin>>c[i],c[i]%=mod;
    for(int i=1;i<n;i++){
        int a,b; cin>>a>>b;
        add(a,b),add(b,a);
    }
    dep[r]=1;
    dfs1(r,0);
    dfs2(r,r);
    build(1,1,n);
    while(m--){
        int op,x,y,z;
        cin>>op;
        if(op==1){
            cin>>x>>y>>z;
            z%=mod;
            update_path(x,y,z);
        }
        else if(op==3){
            cin>>x>>z;
            z%=mod;
            update_tree(x,z);
        }
        else if(op==2){
            cin>>x>>y;
            cout<<query_path(x,y)%mod<<endl;
        }
        else cin>>x,cout<<query_tree(x)%mod<<endl;
    }
    return 0;

}
