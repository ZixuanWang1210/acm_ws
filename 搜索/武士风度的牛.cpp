#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define all(x) x.begin() + 1, x.end()
// #define ll long long
// #define int long long

using namespace std;

int C, R;
char g[155][155];
int d[155][155];
int x, y, H_x, H_y;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
void bfs(int x, int y) {
    queue<pii> q;
    q.push({x, y});
    d[x][y] = 0;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int a = dx[i] + t.first, b = dy[i] + t.second;
            if (d[a][b] || g[a][b] == '*') continue;
            if (a < 0 || a >= C || b < 0 || b >= R) continue;
            d[a][b] = 1 + d[t.first][t.second];
            q.push({a, b});
        }
    }
}

void sol() {
    cin >> R >> C;
    for (int i = 0; i < C; i++) scanf("%s", g[i]);
    for (int i = 0; i < C; i++)
        for (int j = 0; j < R; j++) {
            if (g[i][j] == 'K') x = i, y = j;
            if (g[i][j] == 'H') H_x = i, H_y = j;
        }
    bfs(x, y);
    cout << d[H_x][H_y] << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int _ = 1;
    // cin>>_;
    while (_--) {
        sol();
    }

    return 0;
}
