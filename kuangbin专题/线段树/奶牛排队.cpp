#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=5e4+10;
int n,q;
int h[maxn];
struct node{
    int l,r;
    int mx,mn;
} tr[maxn<<2];


#define root tr[u]
#define ls tr[u<<1]
#define rs tr[u<<1|1]

void pushup(int u){
    root.mx=max(ls.mx,rs.mx);
    root.mn=min(rs.mn,ls.mn);
}

void pushdown(int u){

}

void build(int u,int l,int r){
    if(l==r) root={l,r,h[l],h[l]};
    else{
        tr[u]={l,r};
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

// void modify(int u,int l,int r,int k){
//     if(root.l>=l&&root.r<=r){
//         root.mx=max(k,root.mx);
//         root.mn=min(k,root.mn);
//     }
//     else{
//         pushdown(u);
//         int mid=root.l+root.r>>1;
//         if(l<=mid) modify(u<<1,l,r,k);
//         if(r>mid) modify(u<<1|1,l,r,k);
//         pushup(u);
//     }
// }

int query_max(int u,int l,int r){
    if(l<=root.l&&r>=root.r) return root.mx;
    else{
        pushdown(u);
        int mid=root.l+root.r>>1;
        int res=-0x3f3f3f3f;
        if(l<=mid) res=max(res,query_max(u<<1,l,r));
        if(r>mid) res=max(res,query_max(u<<1|1,l,r));
        return res;
    }
}

int query_min(int u,int l,int r){
    if(l<=root.l&&r>=root.r) return root.mn;
    else{
        pushdown(u);
        int mid=root.l+root.r>>1;
        int res=0x3f3f3f3f;
        if(l<=mid) res=min(res,query_min(u<<1,l,r));
        if(r>mid) res=min(res,query_min(u<<1|1,l,r));
        return res;
    }
}

void sol(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>h[i];

    build(1,1,n);

    while(q--){
        int l,r; cin>>l>>r;
        cout<<query_max(1,l,r)-query_min(1,l,r)<<endl;
    }
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // while(cin>>n){
        sol();
    // }

    return 0;
}
