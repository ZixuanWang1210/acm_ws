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

void sol() {
    ll n, q, sum = 0, x = 0;
    cin >> n >> q;
    ll a[n + 1];
    ll X[n + 1], S[n + 1];
    S[0] = 0, X[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        S[i] = S[i - 1] + a[i];
        X[i] = X[i - 1] ^ a[i];
    }
    while (q--) {
        ll l, r;
        cin >> l >> r;
        sum = S[r] - S[l - 1];
        x = X[r] ^ X[l - 1];
        ll val = sum - x;
        ll len = r - l + 1, res1 = l, res2 = r;
        for (int i = 1; i <= n; i++) {
            int lo = i, hi = n;
            int idx = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (S[mid] - S[i - 1] - (X[mid] ^ X[i - 1]) == val)
                    idx = mid, hi = mid - 1;
                else
                    lo = mid + 1;
            }
            if (idx == -1) continue;
            if (idx - i + 1 < len) len = idx - i + 1, res1 = i, res2 = idx;
        }
        cout << res1 << " " << res2 << "\n";
    }
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
