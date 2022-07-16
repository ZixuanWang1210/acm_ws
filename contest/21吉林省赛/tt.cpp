#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int LL

const int P = 998244853;
unordered_map<int, unordered_map<int, int>> mp;
unordered_map<int, unordered_map<int, int>> Siz;
int n, m, k;
vector<int> path;

int ksm(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = 1ll * a * a % P)
        if (b & 1) res = 1ll * res * a % P;
    return res;
}
int inv(int a) {
    return ksm(a, P - 2) % P;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u > v) swap(u, v);
        mp[u][v] = (mp[u][v] + w) % P;
        Siz[u][v]++;
    }

    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        path.push_back(x);
    }

    LL res = 0;
    for (int i = 1; i < path.size(); i++) {
        int a = path[i - 1], b = path[i];
        if (a > b) swap(a, b);
        if (!mp[a].count(b)) {
            cout << "Stupid Msacywy!";
            return 0;
        }
        int n = Siz[a][b];
        res = (res + mp[a][b] * ksm(10, k - i - 1) % P * inv(n) % P) % P;
    }
    cout << res;

    return 0;
}