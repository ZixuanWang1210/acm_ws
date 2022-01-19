#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
int n, m;
int tr1[maxn], tr2[maxn];
int a[maxn];

int lowbit(int x){
    return x & -x;
}

void add(int x, int k, int tr[]){
    for(; x <= n; x += lowbit(x)) tr[x] += k;
}

int ask(int x, int tr[]){
    int ans = 0;
    for(; x; x-= lowbit(x)) ans += tr[x];
    return ans;
}

int get(int x){
    return ask(x, tr1) * (x + 1) - ask(x, tr2);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        add(i, a[i] - a[i - 1], tr1);
        add(i, i * (a[i] - a[i - 1]), tr2);
    }

    while(m--){
        char op; cin >> op;
        if(op == 'C'){
            int l, r, d; cin >> l >> r >> d;
            add(l, d, tr1), add(r + 1, -d, tr1);
            add(l, l * d, tr2), add(r + 1, (r + 1) * -d, tr2);
        }
        else{
            int l, r; cin >> l >> r;
            cout << get(r) - get(l - 1) << endl;
        }
    }
    

    return 0;
}
