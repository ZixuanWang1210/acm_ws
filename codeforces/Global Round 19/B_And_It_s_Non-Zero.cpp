#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

const int maxn = 2e5 + 10;
int s[20][maxn];

void sol() {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for (int i = 0; i <= 18; i++) {
        ans = max(ans, s[i][r] - s[i][l - 1]);
    }
    cout << r - l + 1 - ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int _ = 1;
    cin >> _;

    for (int i = 0; i <= 18; i += 1)
        for (int j = 1; j <= 200000; j += 1)
            if (j >> i & 1) ++s[i][j];
    for (int i = 0; i <= 18; i += 1)
        for (int j = 1; j <= 200000; j += 1) s[i][j] += s[i][j - 1];
    while (_--) {
        sol();
    }

    return 0;
}
