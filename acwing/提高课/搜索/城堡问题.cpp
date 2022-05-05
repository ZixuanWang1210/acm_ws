#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

const int maxn = 1100;
int mp[maxn][maxn];
int dist[maxn][maxn];
int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
int n, m;

int bfs(int x, int y) {
    dist[x][y] = 0;
    queue<pii> q;
    q.push({x, y});

    int cnt = 0;
    while (q.size()) {
        pii ele = q.front();
        q.pop();
        cnt++;
        int x = ele.first, y = ele.second;
        for (int i = 0; i < 4; i++) {
            if (!(mp[x][y] >> i & 1)) {
                int a = x + dx[i], b = y + dy[i];
                if (dist[a][b] == -1) {
                    dist[a][b] = dist[x][y] + 1;
                    q.push({a, b});
                }
            }
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
        }
    }

    int res = 0, maxv = 0;
    memset(dist, -1, sizeof dist);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == -1) {
                res++;
                maxv = max(maxv, bfs(i, j));
            }
        }
    }
    cout << res << endl << maxv << endl;

    return 0;
}