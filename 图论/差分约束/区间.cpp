#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long int

using namespace std;

const int maxn=5e5+10;
struct node{
    int l,r;
    int cnt;
    int lazy;
} tr[maxn<<2];
struct seg{
    int l,r;
    int c;
    bool operator<(const seg &t) const{
        return r<t.r;
    }
} seg[maxn];
int n;

#define ls tr[u<<1]
#define rs tr[u<<1|1]
#define root tr[u]

void pushup(int u){
    root.cnt=ls.cnt+rs.cnt;
}

void pushdown(int u){
    if(root.lazy){
        ls.lazy=rs.lazy=1;
        ls.cnt=ls.r-ls.l+1;
        rs.cnt=rs.r-rs.l+1;
        root.lazy=0;
    }
}

void build(int u,int l,int r){
    if(l==r) root={l,r,0,0};
    else{
        tr[u]={l,r};
        int mid=(l+r)>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        // pushup(u);
        root.cnt=ls.cnt+rs.cnt;
    }
}

void modify(int u,int l,int r,int k){
    if(root.l>=l&&root.r<=r){
        root.lazy=1;
        root.cnt=1;
        return;
    }
    else{
        pushdown(u);
        int mid=(root.l+root.r)>>1;
        if(l<=mid) modify(u<<1,l,r,k);
        if(r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

int query(int u,int l,int r){
    if(l<=root.l&&r>=root.r) return root.cnt;
    else{
        pushdown(u);
        int mid=(root.l+root.r)>>1;
        if(r<=mid) return query(u<<1,l,r);
        if(l>mid) return query(u<<1|1,l,r);
        return query(u<<1,l,mid)+query(u<<1|1,mid+1,r);
    }
}


void sol(){
    cin>>n;
    int maxx=0;
    for(int i=1;i<=n;i++){
        int a,b,c; cin>>a>>b>>c;
        seg[i]={a,b,c};
        maxx=max(maxx,seg[i].r);
    }
    sort(seg+1,seg+1+n);

    build(1,1,maxx);

    int ans=0;
    for(int i=1;i<=n;i++){
        int l=seg[i].l,r=seg[i].r,c=seg[i].c;
        int sum=query(1,l,r);
        int x=max(0ll,c-sum);
        while(x){
            if(query(1,r,r)) r--;
            else{
                modify(1,r,r,1);
                r--,x--;
                ans++;
            }
        }
    }
    cout<<query(1,1,maxx)<<endl;

}

signed main(){
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
