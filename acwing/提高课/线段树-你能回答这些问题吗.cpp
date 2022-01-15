#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;
const int N = 5e5 + 10;
using namespace std;

int n, m;
int a[N];

struct Node{
    int l, r;
    int sum_l, sum_r;
    int sum_m;
    int sum;
} tr[N * 4];

void pushup(Node &u, Node &l, Node &r){
    u.sum = l.sum + r.sum;
    u.sum_l = max(l.sum_l, l.sum + r.sum_l);
    u.sum_r = max(r.sum_r, r.sum + l.sum_r);
    u.sum_m = max(max(l.sum_m, r.sum_m), l.sum_r + r.sum_l);
}

void pushup(int u){
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r){
    // tr[u].l = l, tr[u].r = r;

    if(l == r) tr[u] = {l, r, a[r], a[r], a[r]};
    else{
        tr[u].l = l, tr[u].r = r;
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    // return;
}

void modify(int u, int x, int v){
    if(tr[u].l == x && tr[u].r == x) tr[u] = {x, x, v, v, v, v};
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

Node query(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r){
        return tr[u];
    }
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(r <= mid) return query(u << 1, l, r);
        else if(l > mid) return query(u << 1 | 1, l, r);
        else{
            auto left = query(u << 1, l, r);
            auto right = query(u << 1 | 1, l, r);
            Node res;
            pushup(res, left, right);
            return res;
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif

    cin >> n >> m;


    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);

    int k, x, y;
    while(m--){

        cin >> k >> x >> y;
        if(k == 1){
            if(x > y) swap(x, y);
            cout << query(1, x, y).sum_m << endl;
        }
        else modify(1, x, y);
    }


    return 0;
}
