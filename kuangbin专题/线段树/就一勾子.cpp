#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=100010;
int n,m,cnt,w[maxn];
struct node{
    int l,r,sum,lazy;
} tr[maxn<<2];

#define root tr[u]
#define ls tr[u<<1]
#define rs tr[u<<1|1]

void pushup(int u){
    root.sum=ls.sum+rs.sum;
}

void pushdown(int u){
    if(root.lazy){
        ls.lazy=root.lazy,rs.lazy=root.lazy;
        ls.sum=(ls.r-ls.l+1)*ls.lazy;
        rs.sum=(rs.r-rs.l+1)*rs.lazy;
        root.lazy=0;
    }
}

void build(int u,int l,int r){
    if(l==r) root={l,r,1,0};
    else{
        tr[u]={l,r};
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r,int k){
    if(root.l>=l&&root.r<=r){
        root.lazy=k;
        root.sum=(root.r-root.l+1)*k;
    }
    else{
        pushdown(u);
        int mid=root.l+root.r>>1;
        if(l<=mid) modify(u<<1,l,r,k);
        if(r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query(int u,int l,int r){
    if(l<=root.l&&r>=root.r) return root.sum;
    else{
        pushdown(u);
        int mid=root.l+root.r>>1;
        int sum=0;
        if(l<=mid) sum+=query(u<<1,l,r);
        if(r>mid) sum+=query(u<<1|1,l,r);
        return sum;
    }
}

void sol(){
    memset(tr,0,sizeof tr);

    cin>>n>>m;
    for(int i=1;i<=n;i++) w[i]=1;
    build(1,1,n);

    while(m--){
        int l,r,v; cin>>l>>r>>v;
        modify(1,l,r,v);
    }
    printf("Case %ld: The total value of the hook is %ld.\n", cnt, query(1, 1, n));
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--){
        cnt++,sol();
    }

    return 0;
}
