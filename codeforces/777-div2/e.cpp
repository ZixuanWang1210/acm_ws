#include <bits/stdc++.h>
#define int long long
using namespace std;

void sol() {
    int n;
    cin >> n;
    int p[n], a[n];
    int nxt[n][30];
    set<int> s, unused;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        p[i] = x;
        s.insert(x);
        unused.insert(i);
        nxt[i][0] = x;
    }
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        mx = max(mx, x);
        if (x < n) {
            unused.erase(x);
        }
        a[i] = x;
    }
    if (unused.size() == 0) {
        for (int i = 0; i < n; ++i) {
            cout << a[i] + 1 << ' ';
        }
        cout << '\n';
        return;
    }
    int rem = s.size();
    int del = n - rem;
    assert(del != 0);
    int steps = (mx - n + 1) / del;
    for (int j = 1; j < 30; ++j) {
        for (int i = 0; i < n; ++i) {
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
        }
    }
    bool vis[n] = {0};
    for (int i = 0; i < n; ++i) {
        int dest = i;
        for (int j = 0; j < 30; ++j) {
            if (steps & (1 << j)) {
                dest = nxt[dest][j];
            }
        }
        auto itr = unused.lower_bound(a[dest]);
        if (vis[dest]) {
            assert(itr != unused.end());
            cout << (*itr) + 1 << ' ';
            unused.erase(itr);
        } else {
            cout << a[dest] + 1 << ' ';
            vis[dest] = 1;
        }
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    int T = 1;

    while (T--) {
        sol();
    }
    return 0;
}