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

const int maxn = 1e4 + 10, maxm = 1e8;
int n, m;
int h[maxn], ne[maxn], e[maxm], w[maxn], idx;
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int col[maxn];
void colored(int u, int c) {
    col[u] = c;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (col[j]) continue;
        colored(j, c ^ 1);
    }
}
template <class T>
struct Flow {
    const int n;
    struct Edge {
        int to;
        T cap;
        Edge(int to, T cap) : to(to), cap(cap) {}
    };
    std::vector<Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<int> cur, h;
    Flow(int n) : n(n), g(n) {}

    bool bfs(int s, int t) {
        h.assign(n, -1);
        std::queue<int> que;
        h[s] = 0;
        que.push(s);
        while (!que.empty()) {
            const int u = que.front();
            que.pop();
            for (int i : g[u]) {
                auto [v, c] = e[i];
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t) {
                        return true;
                    }
                    que.push(v);
                }
            }
        }
        return false;
    }

    T dfs(int u, int t, T f) {
        if (u == t) {
            return f;
        }
        auto r = f;
        for (int &i = cur[u]; i < int(g[u].size()); ++i) {
            const int j = g[u][i];
            auto [v, c] = e[j];
            if (c > 0 && h[v] == h[u] + 1) {
                auto a = dfs(v, t, std::min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0) {
                    return f;
                }
            }
        }
        return f - r;
    }
    void addEdge(int u, int v, T c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    T maxFlow(int s, int t) {
        T ans = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, std::numeric_limits<T>::max());
        }
        return ans;
    }
};
Flow<int> plt(20010);

int dfn[maxn], low[maxn], timestamp;
int stk[maxn], top;
int id[maxn], scc_cnt, siz[maxn];
bool in_stk[maxn];
void tarjan(int u) {
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u, in_stk[u] = true;
    for (auto t : plt.g[u]) {
        int j = plt.e[t].to;
        if (!plt.e[t].cap) continue;
        if (!dfn[j]) {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        } else if (in_stk[j]) {
            low[u] = min(low[u], dfn[j]);
        }
    }
    if (dfn[u] == low[u]) {
        ++scc_cnt;
        int y;
        do {
            y = stk[top--];
            in_stk[y] = false;
            id[y] = scc_cnt;
            siz[scc_cnt]++;
        } while (y != u);
    }
}

void sol() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    for (int i = 1; i <= n; i++) {
        if (!col[i]) colored(i, 2);
    }
    int S = 0, T = 10001;
    for (int i = 1; i <= n; i++) {
        if (col[i] == 2) {
            plt.addEdge(S, i, 1);
            for (int ii = h[i]; ~ii; ii = ne[ii]) {
                int j = e[ii];
                plt.addEdge(i, j, 1);
            }
        } else
            plt.addEdge(i, T, 1);
    }
    // cout<<plt.maxFlow(S,T)<<endl;
    plt.maxFlow(S, T);
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<col[i]<<' ';
    // }
    vector<pii> ans;
    for (int u = 1; u <= n; u++) {
        if (col[u] == 2) {
            for (auto v : plt.g[u]) {
                int j = plt.e[v].to;
                cout << j << ' ';
                if (plt.e[v].cap) continue;
                if (j == S || j == T) continue;
                if (id[u] != id[v]) ans.push_back(u < j ? make_pair(u, j) : make_pair(j, u));
            }
        }
    }
    sort(_all(ans));
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x.first << " " << x.second << endl;
    }
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _ = 1;
    // cin>>_;
    while (_--) {
        sol();
    }

    return 0;
}