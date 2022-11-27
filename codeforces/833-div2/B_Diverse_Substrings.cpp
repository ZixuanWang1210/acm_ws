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
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        vector<int> cnt(10);
        int maxv = 0, diff = 0;
        for (int j = i; j < min(n, i + 100); j++) {
            if (++cnt[s[j] - '0'] == 1) diff++;
            maxv = max(maxv, cnt[s[j] - '0']);
            if (diff >= maxv) ans++;
        }
    }
    cout << ans << endl;
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
