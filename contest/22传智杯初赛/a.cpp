#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define all(x) x.begin() + 1, x.end()
#define _all(x) x.begin(), x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

int n, m;
const int maxn = 1e6 + 10;

void sol() {
    cin >> n >> m;
    vector<int> v(n + 1);
    auto check = [&](int mid, int i) {
        int q = i - 1 + min(i - 1, n - mid) + n - mid;
        if (q <= m)
            return true;
        else
            return false;
    };
    if (m >= n - 1) {
        cout << 0 << endl;

    } else {
        for (int i = 1; i <= n; i++) cin >> v[i];
        sort(all(v));
        int mn = v[n] - v[1];
        for (int i = 1; i <= n; i++) {
            int l = i, r = n;
            int q = i - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (check(mid, i))
                    r = mid;
                else
                    l = mid + 1;
            }

            q = i - 1 + min(i - 1, n - l) + n - l;
            if (q <= m) mn = min(mn, v[l] - v[i]);
        }
        cout << mn;
    }
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
