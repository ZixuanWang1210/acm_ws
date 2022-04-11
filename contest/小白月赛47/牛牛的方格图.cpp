#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n, m;
const int maxn = 1e6;
int mp[1010][1010];
int xl[maxn], xr[maxn], yl[maxn], yr[maxn];
int cnt[maxn];
int b[1010][1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(xl, 0x3f, sizeof xl);
    memset(yl, 0x3f, sizeof yl);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
            int x = mp[i][j];
            xl[x] = min(xl[x], i);
            xr[x] = max(xr[x], i);
            yl[x] = min(yl[x], j);
            yr[x] = max(yr[x], j);
        }
    }
    for (int i = 1; i <= maxn; i++) {
        int x1 = xl[i], y1 = yl[i], x2 = xr[i], y2 = yr[i], c = 1;
        // cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
        if (x1 + x2 + y1 + y2 < 1e7 && !(x1 == x2 && y1 == y2)) {
            b[x1][y1] += c;
            b[x2 + 1][y2 + 1] += c;
            b[x1][y2 + 1] -= c;
            b[x2 + 1][y1] -= c;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            b[i][j] = b[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            if (b[i][j] == 0) ans++;
        }
    cout << ans << endl;

    return 0;
}
