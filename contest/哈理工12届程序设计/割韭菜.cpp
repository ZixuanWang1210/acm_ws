
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0)
#define rep(x,a,b) for(int x=a; x<=b; x++)
#define LL long long


const int N=100005;
int n,m;
LL w[N],sumw[N];
struct node{
    int l,r;
    LL add,sum;
    LL lv,rv;
}tr[N*4];


void pushdown(int u){
    if(tr[u].add){
        LL ad = tr[u].add;
        tr[u<<1].add += ad, tr[u<<1|1].add += ad;
        tr[u].sum += ad*(sumw[tr[u].r]-sumw[tr[u].l-1]);
        tr[u].lv += ad*w[tr[u].l], tr[u].rv += ad*w[tr[u].r];
        tr[u].add = 0;
    }
}

void pushup(int u){
    tr[u].sum = tr[u<<1].sum+tr[u<<1|1].sum;
    tr[u].lv = tr[u<<1].lv;
    tr[u].rv = tr[u<<1|1].rv;
}

void build(int u, int l, int r){
    if(l==r) tr[u] = {l,r,0,0,0};
    else{
        tr[u] = {l,r};
        int mid=l+r>>1;
        build(u<<1, l, mid), build(u<<1|1, mid+1, r);
    }
}

void modify(int u, int l, int r, int val){
    if(tr[u].l>=l && tr[u].r<=r){
        tr[u].add += val;
    }
    else{
        pushdown(u);
        int mid = tr[u].l+tr[u].r>>1;
        if(l<=mid) modify(u<<1,l,r,val);
        if(r>mid) modify(u<<1|1,l,r,val);
        pushup(u);
    }
}

// LL query(int u, int l,int r){
//     if(tr[u].add) pushdown(u);

//     LL sum=0;
//     if(tr[u<<1].rv>val) sum = query(u<<1, val);
//     if(tr[u<<1|1].lv>=val) sum += query(u<<1|1, val);
//     pushup(u);

//     return sum;
// }
LL query(int u, int l,int r){
    #define rt tr[u]

    if(rt.l>=l&&rt.r<=r) return rt.sum;

    pushdown(u);
    int mid=rt.l+rt.r>>1;
    int sum=0;
    if(l<=mid) sum=query(u<<1,l,r);
    if(r>mid) sum=(sum+query(u<<1|1,l,r));
    return sum;
}


void solve(){
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> w[i];
    }
    sort(w+1, w+n+1);
    for(int i=1; i<=n; i++)
        sumw[i] = sumw[i-1]+w[i];
    build(1,1,n);

    int last=0,cur,val;
    while(m--){
        cin >> cur >> val;
        modify(1,1,n,cur-last);
        LL ans = query(1,1,n);
        cout << ans << endl;

        last = cur;
    }
}

int main()
{
    int _ = 1;
    cin >> _;
    while(_--) solve();
    return 0;
}
