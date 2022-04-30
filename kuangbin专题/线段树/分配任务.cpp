// 线段树维护dfs序
// 由于是dfs，同一子树的结点的dfs序一定是连续的，即dfs序连续区间。
// 修改一个点，会把他的所有子孙所在结点全部赋值成一个值。就变成了dfs序的区间更新。
// 查询一个点，就直接查询这个点的dfs序就行。

// link: https://www.cnblogs.com/shuitiangong/p/13908712.html
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n,m;
const int maxn=2e5+10;
int din[maxn],num[maxn],last[maxn],id;

int h[maxn],ne[maxn],e[maxn],idx;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int fa){
    num[u]=++id;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        dfs(j,u);
    }
    last[u]=id;
}

#define root tr[u]
#define ls tr[u<<1]
#define rs tr[u<<1|1]

struct node{
    int l,r;
    int col;
    int lazy;
} tr[maxn<<2];

void build(int u,int l,int r){
    root={l,r,-1,0};
    if(l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    return;
}

void push_down(int u){
    if(root.lazy){
        ls.lazy=rs.lazy=root.lazy;
        ls.col=rs.col=root.lazy;
        root.lazy=0;
    }
}

void update(int u,int l,int r,int k){
    if(root.l>=l&&root.r<=r){
        root.lazy=root.col=k;
        return;
    }
    push_down(u);
    int mid=root.l+root.r>>1;
    if(l<=mid) update(u<<1,l,r,k);
    if(r>mid) update(u<<1|1,l,r,k);
}

// 单点查询
int query(int u,int pos){
    if(root.l==root.r) return root.col;
    push_down(u);
    int mid=root.l+root.r>>1;
    if(pos<=mid) return query(u<<1,pos);
    else return query(u<<1|1,pos);
}

void init(){
    for(int i=1;i<=4*n;i++){
        din[i]=0;
        e[i]=ne[i]=0;
        h[i]=-1;
    }
    idx=0;
}

void sol(){
    cin>>n;
    init();
    build(1,1,n);

    for(int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        din[u]++;
        add(v,u);
    }

    int rt;
    for(int i=1;i<=n;i++){
        if(!din[i]) rt=i;
    }

    id=0;
    dfs(rt,-1);

    cin>>m;
    while(m--){
        string s; cin>>s;
        if(s=="C"){
            int pos; cin>>pos;
            cout<<query(1,num[pos])<<endl;
        }
        else{
            int x,y; cin>>x>>y;
            update(1,num[x],last[x],y);
        }
    }
}

signed main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    for(int i=1;i<=_;i++){
        cout<<"Case #"<<i<<':'<<endl;
        sol();
    }

    return 0;
}
