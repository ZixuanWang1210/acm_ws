#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;
const int N = 2e5 + 10;
using namespace std;

struct Node{
    int l, r;
    int v;
} tr[4 * N];

int m, p;

void pushup(int u){
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

void build(int u, int l, int r){
    tr[u].l = l, tr[u].r = r;
    if(l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    // pushup(u);
}

void modify(int u, int x, int v){
    if(tr[u].l == x && tr[u].r == x){
        tr[u].v = v;
    }
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
    // return;
}

int query(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].v;

    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;
    if(l <= mid) v = query(u << 1, l, r);
    if(r > mid) v = max(v, query(u << 1 | 1, l, r));

    return v;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // #ifdef LOCAL
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    // #endif
    cin >> m >> p;
    int last = 0, cnt = 0;


    build(1, 1, m);

    while(m--){
        char op; cin >> op;
        int l; cin >> l;

        if(op == 'Q'){
            last = query(1, cnt - l + 1, cnt);
            cout << last << endl;
        }
        else{
            modify(1, cnt + 1, ((long long)last + l) % p);
            cnt ++;
        }
    }

    return 0;
}
