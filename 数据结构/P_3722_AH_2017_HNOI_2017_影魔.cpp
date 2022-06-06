#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

const int maxn=2e5+10;
// struct node{
//     int l,r,sum,add;
// } tr[maxn*4];
struct ask{
    int key,l,r,val,id;
    bool operator<(const ask &t) const{
        return key<t.key;
    }
} ask[maxn*2];
struct seg{
    int key,l,r,val;
    bool operator<(const seg &t) const{
        return key<t.key;
    }
} seg[maxn*3];
int ans[maxn];
int k[maxn];
int n,m,p1,p2;
int L[maxn],R[maxn];

//segTree
// struct NODE { int l, r, sum, add; } tr[maxn * 4];
// void pushup(int u) { tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum; }
// void add(int u, int c) { tr[u].add += c, tr[u].sum += (tr[u].r - tr[u].l + 1) * c; }
// void pushdown(int u) { add(u << 1, tr[u].add), add(u << 1 | 1, tr[u].add), tr[u].add = 0; }
// void build(int u, int l, int r) {
//     tr[u].l = l, tr[u].r = r, tr[u].add = tr[u].sum = 0;
//     if (l >= r) return;
//     int mid = (l + r) >> 1;
//     build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
//     pushup(u);
// }
// void modify(int u, int l, int r, int c) {
//     if (tr[u].l >= l && tr[u].r <= r) 
//         return tr[u].add += c, tr[u].sum += (tr[u].r - tr[u].l + 1) * c, void(0);
//     pushdown(u);
//     int mid = (tr[u].l + tr[u].r) >> 1;
//     if (l <= mid) modify(u << 1, l, r, c);
//     if (r > mid) modify(u << 1 | 1, l, r, c);
//     pushup(u);
// }
// int query(int u, int l, int r) {
//     if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
//     pushdown(u);
//     int mid = (tr[u].l + tr[u].r) >> 1, res = 0;
//     if (l <= mid) res += query(u << 1, l, r);
//     if (r > mid) res += query(u << 1 | 1, l, r);
//     return res;
// }
#define ls tr[u<<1]
#define rs tr[u<<1|1]
#define rt tr[u]
struct node{    
    int l,r,sum,add;
} tr[maxn*4];

void pushup(int u){
    rt.sum=ls.sum+rs.sum;
}
void pushdown(int u){
    if(rt.add){
        ls.sum+=(ls.r-ls.l+1)*rt.add;
        rs.sum+=(rs.r-rs.l+1)*rt.add;
        ls.add+=rt.add,rs.add+=rt.add;
        rt.add=0;
    }
}

void build(int u,int l,int r){
    tr[u]={l,r};
    if(l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    pushup(u);
} 

void modify(int u,int l,int r,int c){
    if(rt.l>=l&&rt.r<=r){
        rt.add+=c; 
        rt.sum+=(rt.r-rt.l+1)*c;
        return;
    }
    pushdown(u);
    int mid=rt.l+rt.r>>1;
    if(l<=mid) modify(u<<1,l,r,c);
    if(r>mid) modify(u<<1|1,l,r,c);
    pushup(u);
}

int query(int u,int l,int r){
    if(rt.l>=l&&rt.r<=r){
        return rt.sum;
    }
    pushdown(u);
    int mid=(rt.l+rt.r)>>1,res=0;
    if(l<=mid) res+=query(u<<1,l,r);
    if(r>mid) res+=query(u<<1|1,l,r);
    return res;
}
//

void sol(){
    cin>>n>>m>>p1>>p2;
    for(int i=1;i<=n;i++) cin>>k[i];
    k[0]=k[n+1]=inf;

    for(int i=1;i<=n;i++){
        L[i]=i;
        while(k[i]>=k[L[i]-1]) L[i]=L[L[i]-1];
    }
    for(int i=n;i>=1;i--){
        R[i]=i;
        while(k[i]>=k[R[i]+1]) R[i]=R[R[i]+1];
    }
    for(int i=1;i<=n;i++){
        L[i]-=1,R[i]+=1;
    }

    int cnt_a=0;
    for(int i=1;i<=m;i++){
        int l,r; cin>>l>>r;
        ask[++cnt_a]={l-1,l,r,-1,i}; // 原来的和
        ask[++cnt_a]={r,l,r,1,i}; // 现在的和
        ans[i]=(r-l)*p1;
    }

    sort(ask+1,ask+1+cnt_a);

    int cnt_l=0;
    for(int i=1;i<=n;i++){
        if(L[i]&&R[i]<n+1) seg[++cnt_l]={R[i],L[i],L[i],p1};
        if(L[i]&&R[i]>i+1) seg[++cnt_l]={L[i],i+1,R[i]-1,p2};
        if(L[i]+1<i&&R[i]<n+1) seg[++cnt_l]={R[i],L[i]+1,i-1,p2};
    }
    sort(seg+1,seg+1+cnt_l);

    // for(int i=1;i<=cnt_l;i++){
    //     cout<<seg[i].key<<' '<<seg[i].l<<' '<<seg[i].r<<" "<<seg[i].val<<endl;
    // }

    build(1,1,n);

    for(int i=1,j=1;i<=cnt_a;i++){
        while(j<=cnt_l&&seg[j].key<=ask[i].key) modify(1,seg[j].l,seg[j].r,seg[j].val),j++;
        ans[ask[i].id]+=ask[i].val*(query(1,ask[i].l,ask[i].r));
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<endl;
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
