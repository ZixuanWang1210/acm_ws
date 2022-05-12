#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

#define N 200007

bool vis[N];

int n, rt, f[N], cnt;

vector<int> res[N], son[N];

void dfs(int u, int bel) {
    res[bel].push_back(u);
    if (son[u].empty()) {
        ++cnt;
        return;
    }
    dfs(son[u][0], bel);
    for (int i = 1; i < son[u].size(); ++i) dfs(son[u][i], son[u][i]);
}

void sol() {
    cin >> n;
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
        res[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        cin >> f[i];
        if (f[i] == i)
            rt = i;
        else
            son[f[i]].push_back(i);
    }
    dfs(rt, rt);
    cout << cnt << endl;
    for (int i = 1; i <= n; ++i)
        if (!res[i].empty()) {
            cout<<res[i].size()<<endl;
            for (auto j : res[i]) cout<<j<<' ';
            cout<<endl;
        }
}

signed main() {
    // ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int _ = 1;
    cin >> _;
    while (_--) {
        sol();
    }

    return 0;
}
