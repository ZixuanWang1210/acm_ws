#include <bits/stdc++.h>
using namespace std;

int fa[10010];

int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

int main() {
    for (int i = 1;; i++) {
        for (int i = 0; i < 10010; i++) fa[i] = i;

        int a, b, ok = 1, m = 0;
        bitset<10010> vis, ind;
        while (scanf("%d%d", &a, &b) && a > 0) {
            if (ok) {
                if (find(a) == find(b))
                    ok = 0;
                else
                    fa[fa[a]] = fa[b];
                vis[a] = 1, vis[b] = 1;
                if (ind[b])
                    ok = 0;
                else
                    ind[b] = 1;
                m++;
            }
        }
        if (a == -1) break;
        if (m + 1 != vis.count() && m) ok = 0;
        cout << "Case " << i << " is " << (ok ? "" : "not ") << "a tree.\n";
    }

    return 0;
}