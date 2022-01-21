#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;
#define ls tr[u << 1]
#define rs tr[u << 1 | 1]
#define tu tr[u]
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
struct node{
    int l, r;
    int v;
} tr[maxn * 4];
int n, m;

void build(int u, int l, int r){
    tr[u] = {l, r};
    if(l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void pushup(int u){
    tr[u].v = ls.v + rs.v;
}

void modify(int u, int x, int v){
    if(tr[u].l == u && tr[u].r == u) tr[u].v = x;

    int mid = tr[u].l + tr[u].r >> 1;
    if(x <= mid) modify(u << 1, x, v);
    else modify(u << 1 | 1, u, v);
    pushup(u);
}

int query(int u, int l, int r){
    if(l >= tr[u].l && r <= tr[u].r) return tr[u].v;

    int mid = l + r >> 1;
    int ans = 0;
    if(l <= mid) ans = query(u << 1, l, r);
    if(r > mid) ans = query(u << 1 | 1, l, r);
    return ans;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    build(1, 1, n);

    for(int i = 1; i <= n; i ++){
        int t; cin >> t;
        modify(1, i, t);
    }

    while(m --){
        int op; cin >> op;
        int x, y; cin >> x >> y;
        if(op == 1){
            int k; cin >> k;
            
        }
    }

    

    return 0;
}
