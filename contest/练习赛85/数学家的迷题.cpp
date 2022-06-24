#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

const int maxn=1e5+10,M=5e4+10;
int n,m;
int a[maxn];
int cnt,rk[maxn];
bool st[maxn];
vector<int> fac[maxn];
struct node{
    int l,r;
    bitset<10000> bit;
} tr[M<<2];

void init(){
    for(int i=2;i<=maxn;i++){
        if(!st[i]){
            rk[i]=++cnt;
            for(int j=i;j<=maxn;j+=i){
                st[j]=1;
                fac[j].push_back(i);
            }
        }
    }
}

#define rt tr[u]
#define ls tr[u<<1]
#define rs tr[u<<1|1]

void pushup(int u){
    rt.bit=ls.bit|rs.bit;
    return;
}

void build(int u,int l,int r){
    rt={l,r};
    if(l==r){
        rt.bit.reset();
        for(auto it:fac[a[l]]){
            rt.bit.set(rk[it]);
        }
        return;
    }
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    pushup(u);
}

void modify(int u,int id,int x){
    if(rt.l==rt.r){
        rt.bit.reset();
        for(auto it:fac[x]){
            rt.bit.set(rk[it]);
        }
        return;
    }
    int mid=rt.l+rt.r>>1;
    if(id<=mid) modify(u<<1,id,x);
    else modify(u<<1|1,id,x);
    pushup(u);
}

bitset<10000> query(int u,int l,int r){
    if(rt.l==l&&rt.r==r){
        return tr[u].bit;
    }
    int mid=rt.l+rt.r>>1;
    if(r<=mid) return query(u<<1,l,r);
    else if(l>mid) return query(u<<1|1,l,r);
    else return query(u<<1,l,mid)|query(u<<1|1,mid+1,r);
}

void sol(){
    init();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    build(1,1,n);
    while(m--){
        int op,l,r; cin>>op>>l>>r;
        if(op==1) modify(1,l,r);
        else cout<<query(1,l,r).count() <<endl;
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
