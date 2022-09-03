#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;
char mp[maxn][maxn], bk[maxn][maxn];

void go(int i, int j) {
    bk[i][j] = '.';
    bk[i + 1][j] = '.';
    bk[i][j + 1] = '.';
    bk[i + 1][j + 1] = '.';
}

// id sol() {
//     cin >> n >> m;
//     for (int i = 1; i <= 2 * n; i++) {
//         a[i] = d1[i] = d2[i] = d3[i] = d4[i] = 0;
//     }

//     while (m--) {
//         int typ, pos;
//         cin >> typ >> pos;
//         if (typ == 1) {
//             a[pos]++;
//             a[pos] %= mod;
//         } else if (typ == 2) {
//             d1[pos]++;
//             d1[pos] %= mod;
//         } else {
//             d3[pos]++;
//             d3[pos] %= mod;
//             d3[pos + 1]++;
//             d3[pos + 1] %= mod;
//         }
//     }

//     for (int i = 1; i <= n; i++) {
//         d2[i] += d2[i - 1] + d3[i];
//         d2[i] %= mod;
//     }
//     for (int i = 1; i <= n; i++) {
//         d1[i] += d1[i - 1] + d2[i];
//         d1[i] %= mod;
//     }
//     for (int i = 1; i <= n; i++) {
//         a[i] += a[i - 1] + d1[i];
//         a[i] %= mod;
//         cout << a[i] << ' ';
//     }

//     cout << endl;
// }
void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char t;
            cin >> t;
            mp[i][j] = t;
            bk[i][j] = t;
        }
    }

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= m - 1; j++) {
            int cnt = ((mp[i][j] == '*') + (mp[i + 1][j] == '*') + (mp[i][j + 1] == '*') +
                       (mp[i + 1][j + 1] == '*'));
            if (cnt == 4) {
                cout << "NO" << endl;
                return;
            }
            if (cnt == 3) {
                if (i - 1 >= 1) {
                    if (mp[i - 1][j] == '*' || mp[i - 1][j + 1] == '*') {
                        cout << "NO" << endl;
                        return;
                    }
                }
                if (i + 2 <= n) {
                    if (mp[i + 2][j] == '*' || mp[i + 2][j + 1] == '*') {
                        cout << "NO" << endl;
                        return;
                    }
                }
                if (j - 1 >= 1) {
                    if (mp[i][j - 1] == '*' || mp[i + 1][j - 1] == '*') {
                        cout << "NO" << endl;
                        return;
                    }
                }
                if (j + 2 <= m) {
                    if (mp[i][j + 2] == '*' || mp[i + 1][j + 2] == '*') {
                        cout << "NO" << endl;
                        return;
                    }
                }
                if (i - 1 >= 1 && j - 1 >= 1) {
                    if (mp[i][j] == '.') {
                        // bk[i][j] = '.';
                        // bk[i + 1][j] = '.';
                        // bk[i][j + 1] = '.';
                        // bk[i + 1][j + 1] = '.';
                        go(i, j);
                        continue;
                    }
                    if (mp[i - 1][j - 1] == '*') {
                        cout << "NO" << endl;
                        return;
                    }
                }
                if (i - 1 >= 1 && j + 2 <= m) {
                    if (mp[i][j + 1] == '.') {
                        // bk[i][j] = '.';
                        // bk[i + 1][j] = '.';
                        // bk[i][j + 1] = '.';
                        // bk[i + 1][j + 1] = '.';
                        go(i, j);
                        continue;
                    }
                    if (mp[i - 1][j + 2] == '*') {
                        cout << "NO" << endl;
                        return;
                    }
                }
                if (i + 2 <= n && j - 1 >= 1) {
                    if (mp[i + 1][j] == '.') {
                        // bk[i][j] = '.';
                        // bk[i + 1][j] = '.';
                        // bk[i][j + 1] = '.';
                        // bk[i + 1][j + 1] = '.';
                        go(i, j);
                        continue;
                    }
                    if (mp[i + 2][j - 1] == '*') {
                        cout << "NO" << endl;
                        return;
                    }
                }
                if (i + 2 <= n && j + 2 <= m) {
                    if (mp[i + 2][j + 2] == '*') {
                        if (mp[i + 1][j + 1] == '.') {
                            // bk[i][j] = '.';
                            // bk[i + 1][j] = '.';
                            // bk[i][j + 1] = '.';
                            // bk[i + 1][j + 1] = '.';
                            go(i, j);
                            continue;
                        }
                        cout << "NO" << endl;
                        return;
                    }
                }
                // bk[i][j] = '.';
                // bk[i + 1][j] = '.';
                // bk[i][j + 1] = '.';
                // bk[i + 1][j + 1] = '.';
                go(i, j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (bk[i][j] == '*') {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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
