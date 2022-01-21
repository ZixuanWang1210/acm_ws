#include <bits/stdc++.h>
#define endl "\n"
#define ls tr[u << 1]
#define rs tr[u << 1 | 1]
#define tu tr[u]
using namespace std;

const int maxn = 5e5 + 10;
int n, m;
int a[maxn];

struct node{
    int l, r;
    int lsum, rsum, msum;
    int sum; 
} tr[maxn * 4];


void pushup(node &u, node &l, node &r)
{
    u.sum = l.sum + r.sum;
    u.lsum = max(l.lsum, l.sum + r.lsum);
    u.rsum = max(r.rsum, r.sum + l.rsum);
    u.msum = max(max(l.msum, r.msum), l.rsum + r.lsum);
}

void pushup(int u)
{
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

// void pushup(int u){
//     tu.sum = ls.sum + rs.sum;
//     tu.lsum = max(ls.lsum, ls.sum + rs.lsum);
//     tu.rsum = max(rs.rsum, rs.sum + ls.rsum);
//     tu.msum = max(max(ls.msum, rs.msum), ls.rsum + rs.lsum);
// }

void build(int u, int l, int r){
    if(l == r) tu = {l, r, a[r], a[r], a[r], a[r]};
    else{
        tu = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, int v){
    if(tu.l == x && tu.r == x) tu = {x, x, v, v, v, v};
    else{
        int mid = tu.l + tu.r >> 1;
        if(x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

// node query(int u, int l, int r){
//     if(l <= ls.l && r >= rs.r) return tu;
//     else{
//         int mid = tu.l + tu.r >> 1;
//         node ans = 0;
//         if(l <= mid) ans = query(u << 1, l, r);
//         if(r > mid) ans = max(ans, query(u << 1 | 1, l, r));
//         return ans;
//     }
// }
node query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u];
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid) return query(u << 1, l, r);
        else if (l > mid) return query(u << 1 | 1, l, r);
        else
        {
            auto left = query(u << 1, l, r);
            auto right = query(u << 1 | 1, l, r);
            node res;
            // res.sum = left.sum + right.sum;
            // res.lsum = max(left.lsum, left.sum + right.lsum);
            // res.rsum = max(right.rsum, right.sum + left.rsum);
            // res.msum = max(max(left.msum, right.msum), left.msum + right.msum);
            pushup(res, left, right);
            return res;
        }
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    build(1, 1, n);

    int k, x, y;
    while(m--){
        cin >> k >> x >> y;
        if(k == 1){
            if(x > y) swap(x, y);
            cout << query(1, x, y).msum << endl;
        }
        else modify(1, x, y);
    }
    

    return 0;
}
