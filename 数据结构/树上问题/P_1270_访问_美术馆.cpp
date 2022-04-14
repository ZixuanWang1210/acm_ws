#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 2010;
struct graph {
    vector<int> e, h, w, ne;
    int n, idx;
    graph(int n) : e(2 * n + 1), h(n + 1), w(2 * n + 1), ne(2 * n + 1) {
        for (int i = 0; i < 2 * n + 1; i++) {
            e[i] = w[i] = ne[i] = 0;
            if (i <= n) h[i] = -1;
        }
    }
    void add(int a, int b) {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }
    void add(int a, int b, int c) {
        e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    }
};

int n;
int root, tot;
int dp[maxn][maxn];
int ans;
int size[maxn];
graph g(20000);

void insert(int x, int fa) {
    int time, pic;
    scanf("%d %d", &time, &pic);
    g.add(fa, x, time << 1);
    if (!pic) {
        insert(++tot, x);
        insert(++tot, x);
    } else {
        while (pic--) g.add(x, 0, 5);
    }
}

void dfs(int u) {
    for (int i = g.h[u]; ~i; i = g.ne[i]) {
        int v = g.e[i], w = g.w[i];
        dfs(v);
        size[u] += size[v] + w;
        for (int j = min(n, size[u]); j >= w; j--)
            for (int k = 0; k <= min(j - w, size[v]); k++)
                dp[u][j] = max(dp[u][j], dp[u][j - k - w] + dp[v][k]);
    }
}

int main() {

    cin >> n;
    n--;
    root = tot = 1;
    insert(++tot, root);
    dp[0][0] = 1;
    dfs(root);
    for (int i = 1; i < n; i++) {
        ans = max(ans, dp[root][i]);
    }
    cout << ans << endl;

    return 0;
}
