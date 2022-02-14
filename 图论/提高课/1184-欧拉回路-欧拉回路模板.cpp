#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int N = 6e5 + 10, M = 6e5 + 10;
int h[N], ne[M], e[M], idx;
int ans[N], cnt;
int n, type, m;
int din[N], dout[N];
int used[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
    for (int &i = h[u]; ~i;) {
        if (used[i]) {
            i = ne[i];
            continue;
        }

        used[i] = true;
        if (type == 1) used[i ^ 1] = true;

        int t;
        if (type == 1) {
            t = i / 2 + 1;
            if (i & 1) t = -t;
        } else
            t = i + 1;

        int j = e[i];
        i = ne[i];
        dfs(j);
        ans[cnt++] = t;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> type >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        if (type == 1) add(b, a);
        dout[a]++, din[b]++;
    }

    if (type == 1) {
        for (int i = 1; i <= n; i++) {
            int t = din[i] + dout[i];
            if (t & 1) {
                cout << "NO" << endl;
                return 0;
            }
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (din[i] != dout[i]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (~h[i]) {
            dfs(i);
            break;
        }
    }
    if (cnt < m) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    for (int i = cnt - 1; i >= 0; i--) cout << ans[i] << ' ';
    return 0;
}
