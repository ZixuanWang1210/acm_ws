#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n, k;
const int N = 300;
int f[N];
struct node {
    int u, v, w;
    bool operator<(const node &t) const {
        return w < t.w;
    }
} edge[N];
int idx;

int find(int x) {
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 0; i < k; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[++idx] = {u, v, w};
    }

    sort(edge + 1, edge + 1 + k);

    int ans = 0;
    for (int i = 1; i <= k; i++) {
        int a = find(edge[i].u), b = find(edge[i].v), w = edge[i].w;
        if (a != b)
            f[a] = b;
        else
            ans += w;
    }

    cout << ans;

    return 0;
}
