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

const int maxn=4e5+10;
struct node{
    int l,r;
    int w;
    int lazy;
} tr[maxn<<2];
int a[maxn];
int n;

#define rt tr[u]
#define ls tr[u<<1]
#define rs tr[u<<1|1]

void pushup(int u){
    rt.w=ls.w+rs.w;
}

void pushdown(int u){
    if(rt.lazy){
        ls.w=max(ls.w,rt.lazy);
        rs.w=max(rs.w,rt.lazy);
        ls.lazy=max(ls.lazy,rt.lazy);
        // if(ls.l==ls.r&&ls.w<ls.lazy) ls.w=ls.lazy,ls.lazy=0;
        rs.lazy=max(rs.lazy,rt.lazy);
        // if(rs.l==rs.r&&rs.w<rs.lazy) rs.w=rs.lazy,rs.lazy=0; 
        rt.lazy=0;
    }
}

void build(int u,int l,int r){
    if(l==r) rt={l,l,a[l],0};
    else{
        tr[u]={l,r};
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r,int k){
    if(rt.l>=l&&rt.r<=r){
        rt.w=k;
    }
    else{
        pushdown(u);
        int mid=rt.l+rt.r>>1;
        if(l<=mid) modify(u<<1,l,r,k);
        if(r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

void modify2(int u,int l,int r,int k){
    // if(rt.l>=l&&rt.r<=r){
        rt.lazy=max(rt.lazy,k);
        rt.w=max(rt.w,k);
    // }
    // else{
    //     pushdown(u);
    //     int mid=rt.l+rt.r>>1;
    //     if(l<=mid) modify(u<<1,l,r,k);
    //     if(r>mid) modify(u<<1|1,l,r,k);
    //     pushup(u);
    // }
}

int query(int u,int l,int r){
    if(l<=rt.l&&r>=rt.r) return rt.w;
    else{
        pushdown(u);
        int mid=rt.l+rt.r>>1;
        int sum=0;
        if(l<=mid) return query(u<<1,l,r);
        if(r>mid) return query(u<<1|1,l,r);
        // return sum;
    }
    return 0;
}


void sol(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    build(1,1,n);

    int q; cin>>q;
    while(q--){
        int op; cin>>op;
        if(op==1){
            int p,x; cin>>p>>x;
            modify(1,p,p,x);
        }
        else{
            int x; cin>>x;
            modify2(1,1,n,x);
        }
    }

    for(int i=1;i<=n;i++){
        cout<<query(1,i,i)<<' ';
    }
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
