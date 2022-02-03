#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define root tr[u]
#define ls tr[u<<1]
#define rs tr[u<<1|1]
using namespace std;

const int N=1e6+10;
int n,m,q,ans;
int a[N],b[N];
struct op{
    int op,l,r;
} opt[N];
int idx;
struct node{
    int l,r;
    int sum,lazy;
} tr[N*4];

void build(int u,int l,int r){
    tr[u]={l,r};
    if(l==r){
        tr[u]={l,r,0,0};
        return;
    }
    else{
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        return;
    }
}

void pushup(int u){
    root.sum=ls.sum+rs.sum;
    return;
}

void pushdown(int u){
    if(root.lazy==1){
        ls.sum=(ls.r-ls.l+1),ls.lazy=1;
        rs.sum=(rs.r-rs.l+1),rs.lazy=1;
    }
    else{
        ls.sum=0,ls.lazy=2;
        rs.sum=0,rs.lazy=2;
    }
    root.lazy=0;
}

void modify(int u,int l,int r,int t){
    if(l<=root.l&&r>=root.r){
        if(t==0) root.sum=root.r-root.l+1,root.lazy=1;
        else root.sum=0,root.lazy=2;
        return;
    }
    if(root.lazy) pushdown(u);
    int mid=root.l+root.r>>1; //注意
    if(l<=mid) modify(u<<1,l,r,t);
    if(r>mid) modify(u<<1|1,l,r,t);
    pushup(u);
}

int query(int u,int l,int r){
    if(l<=root.l&&r>=root.r){
        return root.sum;
    }
    else{
        if(root.lazy) pushdown(u);
        int mid=root.l+root.r>>1,ans=0; //注意
        if(l<=mid) ans+=query(u<<1,l,r);
        if(r>mid) ans+=query(u<<1|1,l,r);
        return ans;
    }
}

bool check(int x){
    build(1,1,n);
    for(int i=1;i<=n;i++){
        modify(1,i,i,a[i]>=x);
    }
    for(int i=1;i<=m;i++){
        int op=opt[i].op,l=opt[i].l,r=opt[i].r;
        int t=query(1,l,r);
        if(op==0){
            modify(1,l,l+t-1,0);
            modify(1,l+t,r,1);
        }
        else{
            modify(1,l,r-t,1);
            modify(1,r-t+1,r,0);
        }
    }
    return query(1,q,q)==0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    int _max=-1,_min=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        _max=max(_max,a[i]);
        _min=min(_min,a[i]);
    }
    for(int i=1;i<=m;i++){
        int op,l,r; cin>>op>>l>>r;
        opt[++idx]={op,l,r};
    }
    cin>>q;

    int l=_min,r=_max;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
    
    return 0;
}
