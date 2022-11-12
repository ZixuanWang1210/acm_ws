#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define all(x) x.begin() + 1, x.end()
#define _all(x) x.begin(), x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

const int maxn = 2e7 + 10;
int nxt[maxn];
int len;
int n;
int a[maxn];

void init() {
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && a[i] != a[j + 1]) j = nxt[j];
        if (a[i] == a[j + 1]) j++;
        nxt[i] = j;
    }
}

void sol() {
    int x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        a[i] = __gcd((i * x) ^ x, x);
    }
    init();
    int res = 0;
    cout << n - nxt[n] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _ = 1;
    // cin>>_;
    while (_--) {
        sol();
    }

    return 0;
}
