#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

const int maxn = 5e5 + 10;
int n, m;
int tr[maxn], a[maxn];

int lowbit(int x){
    return x & -x;
}

void add(int x, int k){
    for(; x <= n; x += lowbit(x)) tr[x] += k;
}

int ask(int x){
    int ans = 0;
    for(; x; x -= lowbit(x)) ans += tr[x];
    return ans;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        add(i, a[i] - a[i - 1]);
    }

    while(m--){
        int op; cin >> op;
        if(op == 1){
            int x, y, k; cin >> x >> y >> k;
            add(x, k), add(y + 1, -k);
        }
        else{
            int k; cin >> k;
            cout << ask(k) << endl;
        }
    }
    

    return 0;
}
