#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define all(x) x.begin() + 1, x.end()
#define _all(x) x.begin(), x.end()
// #define ll long long
#define int long long

using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> v(n + 1), b(n + 1);
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        b[i] = v[i] - v[i - 1];
    }
    for (int i = 2; i <= n; i++) {
        if (b[i] < 0)
            ans -= b[i], b[1] += b[i];
        else
            ans += b[i];
    }
    cout << ans + abs(b[1]) << endl;
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
