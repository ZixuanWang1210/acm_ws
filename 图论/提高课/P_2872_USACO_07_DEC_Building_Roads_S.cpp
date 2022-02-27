//最小生成树
#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long
#define double long double
using namespace std;

const int maxn = 1000 * 1000 + 10;
struct node {
    int u, v;
    double w;
    bool operator<(const node& t) const {
        return w < t.w;
    }
} edge[maxn];
int n, m;
int p[maxn];
pii e[maxn];

double _get(pii a, pii b) {
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    // cout<<dx<<' '<<dy<<' ' <<sqrt((double)dx * (double)dx + (double)dy * (double)dy)<<endl;
    return sqrt((double)dx * (double)dx + (double)dy * (double)dy);
}

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

signed main() {
    cin >> n >> m;
    double re = 0;
    for (int i = 1; i <= n; i++) {
        cin >> e[i].first >> e[i].second;
    }
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            edge[++idx] = {i, j, _get(e[i], e[j])};
        }
    }
    // for (int i = 1; i <= m; i++) {
    //     int u, v;
    //     cin >> u >> v;
    //     // re+=_get(e[u],e[v]);
    //     edge[++idx] = {u, v, 0};
    // }

    sort(edge + 1, edge + 1 + idx);

    for (int i = 1; i <= n; i++) p[i] = i;

    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        u=find(u),v=find(v);
        p[u]=v;
    }

    double res = 0;
    int cnt = 0;
    for (int i = 1; i <= idx; i++) {
        int u = edge[i].u, v = edge[i].v;
        double w = edge[i].w;
        int a = find(u), b = find(v);
        if (a != b) {
            p[a] = b;
            res += w;
            if (++cnt >= n - 1) break;
        }
    }
    cout << fixed << setprecision(2) << res << endl;

    return 0;
}
