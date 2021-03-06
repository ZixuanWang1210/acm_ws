#include <bits/stdc++.h>
#define endl "\n"
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long
using namespace std;

const int maxn = 2e5 + 10;
int n, m;
int ans1, ans2;
int a[maxn], upper[maxn], lower[maxn];
int tr[maxn];

int lowbit(int x){
    return x & -x;
}

void add(int a, int b){
    for(; a <= n; a += lowbit(a)) tr[a] += b;
}

int ask(int x){
    int ans = 0;
    for(; x; x -= lowbit(x)) ans += tr[x];
    return ans;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    for(int i = 1; i <= n; i ++){
        int y = a[i];
        lower[i] = ask(y - 1);
        upper[i] = ask(n) - ask(y);

        add(y, 1);
    }
    
    memset(tr, 0, sizeof tr);

    for(int i = n; i >= 1; i --){
        int y = a[i];
        ans2 += ask(y - 1) * lower[i];
        ans1 += (ask(n) - ask(y)) * upper[i];        
        add(y, 1);
    }

    cout << ans1 << " " << ans2;

    return 0;
}
