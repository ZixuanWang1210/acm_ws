#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
typedef long long ll;
// typedef unsigned long long ull;
#define ls tr[u<<1]
#define rs tr[u<<1|1]
#define rt  tr[u]
using namespace std;

const int N=8;
int n,P,m;
int a[N];
struct node{
    int l,r;
    int sum;
    int add,mlt;
} tr[N*4];

void pushup(int u){
    rt.sum=(ls.sum+rs.sum)%P;
}

void build(int u, int l, int r){
    tr[u]={l,r};
    if(l==r){
        tr[u]={l,r,a[l],0,1};
    }
    else{
        tr[u]={l,r,0,0,1};
        int mid=l+r>>1;
        build(u<<1,l,mid), build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void pushdown(int u){
    ls.add=(ls.add*rt.mlt+rt.add)%P;
    ls.mlt=ls.mlt*rt.mlt%P;
    ls.sum=(ls.sum*rt.mlt+rt.add*(ls.r-ls.l+1))%P;
    rs.add=(rs.add*rt.mlt+rt.add)%P;
    rs.mlt=rs.mlt*rt.mlt%P;
    rs.sum=(rs.sum*rt.mlt+rt.add*(rs.r-rs.l+1))%P;
    rt.add=0,rt.mlt=1;//忘记！！！
}

void modify(int u,int l,int r,int add,int mul){
    if(rt.l>=l&&rt.r<=r){
        rt.sum=rt.sum*mul+add*(rt.r-rt.l+1);
        rt.add=(mul*rt.add+add)%P;
        rt.mlt=mul*rt.mlt%P;
    }
    else{
        pushdown(u);
        int mid=rt.l+rt.r>>1;
        if(l<=mid) modify(u<<1,l,r,add,mul);
        if(r>mid) modify(u<<1|1,l,r,add,mul);
        pushup(u);
    }
}

int query(int u,int l,int r){
    if(rt.l>=l&&rt.r<=r) return rt.sum;

    pushdown(u);
    int mid=rt.l+rt.r>>1;
    int sum=0;
    if(l<=mid) sum=query(u<<1,l,r);
    if(r>mid) sum=(sum+query(u<<1|1,l,r))%P;
    return sum;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>P;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);

    // cin>>m;
    while(m--){
        int t,l,r,d;
        cin>>t>>l>>r;
        if(t==1){
            cin>>d;
            modify(1,l,r,0,d);
        }
        else if(t==2){
            cin>>d;
            modify(1,l,r,d,1);
        }
        else cout<<query(1,l,r)<<endl;
    }
    

    return 0;
}
