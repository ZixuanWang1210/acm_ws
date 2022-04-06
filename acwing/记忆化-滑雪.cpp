#include <algorithm>
#include <iostream>
using namespace std;

const int N = 310;
int R, C;

int a[N][N];
int dp[N][N];

int _maxn = -1;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dfs(int x, int y) {
    if (dp[x][y] != 0) return dp[x][y];

    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];

        if (newx >= 0 && newx < R && newy >= 0 && newy < C && a[newx][newy] < a[x][y]) {
            dp[x][y] = max(dp[x][y], dfs(newx, newy) + 1);
        }
    }
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int len = dfs(i, j);
            _maxn = max(_maxn, len);
        }
    }

    cout << _maxn + 1 << endl;

    return 0;
}
