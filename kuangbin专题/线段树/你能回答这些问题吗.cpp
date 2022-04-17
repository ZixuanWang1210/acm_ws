#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=100005;

int n,m,w[maxn];
struct node{
    int l,r;
    int sum;
} tr[maxn<<2];

#define root tr[u]
#define ls tr[u<<1]
#define rs tr[u<<1|1]

void pushup(int u){
    root.sum=ls.sum+rs.sum;
}

void pushdown(int u){
}

void build(int u,int l,int r){
    if(l==r) root={l,r,w[r]};
    else{
        tr[u]={l,r};
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r){
    if(tr[u].r - tr[u].l + 1 == tr[u].sum) return ;
    if(root.l>=l&&root.r<=r&&tr[u].l==tr[u].r){
        tr[u].sum=sqrt(tr[u].sum);
    }
    else{
        pushdown(u);
        int mid=root.l+root.r>>1;
        if(l<=mid) modify(u<<1,l,r);
        if(r>mid) modify(u<<1|1,l,r);
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


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int idx=0;
    while(cin>>n){
        cout<<"Case #"<<++idx<<':'<<endl;
        for(int i=1;i<=n;i++) cin>>w[i];
        build(1,1,n);
        cin>>m;
        while(m--){
            int cz,a,b; cin>>cz>>a>>b;
            if(a>b) swap(a,b);
            if(cz==0) modify(1,a,b);
            else if(cz==1) cout<<query(1,a,b)<<endl;
        }
        cout<<endl;
    }
    return 0;
}
