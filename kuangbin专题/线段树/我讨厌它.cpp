#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define ls tr[u>>1]
#define rs tr[u>>1|1]
#define rt tr[u]
using namespace std;

const int maxn=1e7;
struct node{
    int l,r,v;
} tr[maxn];
int n,m;
int w[maxn];

void pushup(int u){
    // rt.v=max(ls.v,rs.v);
    rt.v=max(tr[u<<1].v,tr[u<<1|1].v);
}

void build(int u,int l,int r){
    tr[u]={l,r,w[r]};
    if(l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int x,int v){
    if(rt.l==x&&rt.r==x) rt.v=v;
    else{
        int mid=rt.l+rt.r>>1;
        if(x<=mid) modify(u<<1,x,v);
        else modify(u<<1|1,x,v);
        pushup(u);
    }
}

int query(int u,int l,int r){
    if(l<=rt.l&&rt.r<=r) return rt.v;
    int mid=rt.l+rt.r>>1;
    int v=0;
    if(l<=mid) v=query(u<<1,l,r);
    if(r>mid) v=max(v,query(u<<1|1,l,r));
    return v;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    while(cin>>n>>m){
        memset(tr,0,sizeof tr);
        memset(w,0,sizeof w);
        for(int i=1;i<=n;i++) cin>>w[i];

        build(1,1,n);

        while(m--){
            string op; cin>>op;
            int a,b;
            cin>>a>>b;
            if(op=="U") modify(1,a,b);
            else cout<<query(1,a,b)<<endl;

        }
    }

    return 0;
}
