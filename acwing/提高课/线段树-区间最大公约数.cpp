#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

const int maxn = 5e5 + 10;
int n, m;
ll a[maxn], b[maxn];
struct node{
    int l, r;
    ll gcd, sum;
} tr[4* maxn];

void pushup(node &u, node &l, node &r){
    u.sum = l.sum + r.sum;
    u.gcd = __gcd(l.gcd, r.gcd);
}

void pushup(int u){
    return pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r){
    if(l == r) tr[u] = {l, r, b[l], b[l]};
    else{
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, ll v)
{
    if (tr[u].l == x && tr[u].r == x)
    {
        ll b = tr[u].sum + v;
        tr[u] = {x, x, b, b};
    }
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}


node query(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u];
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) query(u << 1, l, r);
        else if(r > mid) query(u << 1 | 1, l, r);
        else{
            auto left = query(u << 1, l, r);
            auto right = query(u << 1 | 1, l, r);
            node res;
            pushup(res, left, right);
            return res;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }

    build(1, 1, n);

    while(m--){
        char op; cin >> op;
        int l, r; cin >> l >> r;
        if(op =='C'){
            ll d; cin >> d;
            modify(1, l, d);
            if (r + 1 <= n) modify(1, r + 1, -d);
        }
        else{
            auto left = query(1, 1, l);
            node right({0, 0, 0, 0});
            if (l + 1 <= r) right = query(1, l + 1, r);
            cout << abs(__gcd(left.sum, right.gcd)) << endl;
        }
    }

    return 0;
}
