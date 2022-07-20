#include <bits/stdc++.h>
using namespace std;
const int N = 110, M = N * N / 2;
int h[N], e[M], ne[M], w[M], idx;
int q[N];
int din[N], dout[N];
int f[N];
int n, m;
void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
void topsort() {
    int tt = -1, hh = 0;
    for (int i = 1; i <= n; ++i)
        if (!din[i]) q[++tt] = i;
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            din[j]--;
            if (!din[j]) q[++tt] = j;
        }
    }
}
int main() {
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> f[i] >> a;
        if (!f[i]) f[i] -= a;
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        din[b]++;
        dout[a]++;
    }
    topsort();
    for (int i = 0; i < n; ++i) {
        int j = q[i];
        if (f[j] > 0) {
            for (int k = h[j]; k != -1; k = ne[k]) {
                f[e[k]] += w[k] * f[j];
            }
        }
    }
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        if (!dout[i] && f[i] > 0) {
            printf("%d %d\n", i, f[i]);
            flag = false;
        }
    }
    if (flag) puts("NULL");
    return 0;
}
