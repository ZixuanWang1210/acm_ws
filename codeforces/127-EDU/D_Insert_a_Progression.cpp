#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol() {
    int n, x;
    cin >> n >> x;
    ll ans = 0;
    ll a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) ans += abs(a[i] - a[i - 1]);
    ll minv = *min_element(a + 1, a + 1 + n), maxv = *max_element(a + 1, a + 1 + n);

    ll t = 1e9;
    t = min(t, a[1] - 1);
    t = min(t, a[n] - 1);
    for (int i = 1; i < n; i++) {
        t = min(t, abs(a[i] - 1) + abs(a[i + 1] - 1) - abs(a[i + 1] - a[i]));
    }
    ans += t;

    if (x <= maxv) {
        cout << ans << '\n';
        return;
    }

    t = 1e9;
    t = min(t, x - a[1]);
    t = min(t, x - a[n]);

    for (int i = 1; i < n; i++) {
        t = min(t, abs(a[i] - x) + abs(a[i + 1] - x) - abs(a[i + 1] - a[i]));
    }
    ans += t;

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int _ = 1;
    cin >> _;
    while (_--) {
        sol();
    }

    return 0;
}
