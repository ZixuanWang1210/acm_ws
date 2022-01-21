#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const int maxn = 200010;
int m, p;
char op;
struct node{
    int l, r;
    int v;
} tr[maxn * 4];

void pushup(int u){
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

void build(int u, int l, int r){ // 建立空树
    tr[u] = {l, r};
    if(l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

int query(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].v;

    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;
    if(l <= mid) v = query(u << 1, l, r); //注意
    if(r > mid) v = max(v, query(u << 1 | 1, l, r));
    return v;
}

void modify(int u, int x, int v){//x为下标，v为值
    if(tr[u].l == x && tr[u].r == x) tr[u].v = v;
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> m >> p;

    int last = 0, idx = 0;;
    build(1, 1, m);
    while(m --){
        cin >> op;
        int x; cin >> x;
        if(op == 'Q'){
            last = query(1, idx - x + 1, idx);
            cout << last << endl;
        }
        else{
            modify(1, idx + 1, ((long long)last + x) % p);
            idx ++;
        }
    }
    

    return 0;
}
