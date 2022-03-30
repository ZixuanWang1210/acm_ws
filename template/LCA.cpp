#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn = 5e6 + 10;
int h[maxn], ne[maxn], e[maxn], idx;
int n, m, s;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

struct LCA {
    /*
    $st[cnt][0]$：树的$dfs$序，第$cnt$个遍历的点是$st[cnt][0]$
    $dfn[x]$：节点编号为x的节点，第一次出现在dfs序中的位置
    $dep[x]$：节点x在树中的深度
    */

    int dfn[maxn], dep[maxn], st[maxn][30], cnt;
    void dfs(int x, int fa) {
        dfn[x] = ++cnt, dep[x] = dep[fa] + 1, st[cnt][0] = x;
        for (int i = h[x]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == fa) continue;
            dfs(j, x);
            st[++cnt][0] = x;
        }
    }

    void RMQ() {
        for (int j = 1; j <= 20; j++) {
            for (int i = 1; (i + (1 << j) - 1) <= cnt; i++) {
                int r = i + (1 << (j - 1));
                st[i][j] = dep[st[i][j - 1]] < dep[st[r][j - 1]] ? st[i][j - 1] : st[r][j - 1];
            }
        }
    }

    int get(int l, int r) {
        l = dfn[l], r = dfn[r];
        if (l > r) swap(l, r);
        int k = log2(r - l + 1);
        int res = dep[st[l][k]] < dep[st[r - (1 << k) + 1][k]] ? st[l][k] : st[r - (1 << k) + 1][k];
        return res;
    }

} plt;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }

    plt.dfs(s, -1);
    plt.RMQ();

    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << plt.get(a, b) << endl;
    }

    return 0;
}
