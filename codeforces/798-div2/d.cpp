#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define all(x) x.begin() + 1, x.end()
#define _all(x) x.begin(), x.end()
// #define ll long long
// #define int long long

using namespace std;

int n, m, cnt;
int b[5];
char g[1010][1010];
int get(int i, int j) {
    return max({b[0] - i - j, b[1] - i + j, b[2] + i - j, b[3] + i + j});
}
void sol() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> g[i][j];

    for (int i = 0; i <= 3; i++) b[i] = -n - m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 'B') {
                b[0] = max(b[0], i + j);
                b[1] = max(b[1], i - j);
                b[2] = max(b[2], -i + j);
                b[3] = max(b[3], -i - j);
            }

    int x = 0, y = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (get(i, j) < get(x, y)) x = i, y = j;

    x++, y++;
    cout << x << " " << y << '\n';
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
