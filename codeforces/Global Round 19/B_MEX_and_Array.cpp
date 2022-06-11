#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define all(x) x.begin() + 1, x.end()
#define _all(x) x.begin(), x.end()
#define ll long long
// #define int long long

using namespace std;

void sol() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll tot = 0;
    for (int i = 2; i < n; i++) tot += a[i];
    int even = 0, odd = 0;
    for (int i = 2; i < n; i++)
        if (a[i] % 2)
            odd++;
        else
            even++;
    if (count(a + 2, a + n, 1) == n - 2 || (n == 3 && a[2] % 2)) {
        cout << -1 << '\n';
        return;
    }
    cout << (tot + odd) / 2 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_--) {
        sol();
    }

    return 0;
}
