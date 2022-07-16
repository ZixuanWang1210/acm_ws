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
const int N = 1e5 + 10;
int n, k, m;
int cnt[N], a[N];
ll res[N];
bool st[N];

void sol() {
    cin >> n >> k >> m;
    for (int i = 0; i < N; i++) {
        cnt[i] = 0, res[i] = 0, st[i] = false;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll t;
    if (m / n % 2) {
        t = m / n - 1;
        m = m % n + n;
        //cout << m << endl;
    } else {
        t = m / n;
        m %= n;
    }
    //cout << t << endl;

    for (int i = 0; i < n; i++) {
        if (cnt[a[i]] & 1)
            res[i] += t / 2;
        else {
            if (st[a[i]]) {
                res[i] += t;
                st[a[i]] = false;
            } else
                st[a[i]] = true;
        }
    }

    memset(st, 0, sizeof st);
    for (int i = 0; i < m; i++) {
        if (st[a[i % n]]) {
            st[a[i % n]] = false;
            res[i%n]++;
        } else
            st[a[i % n]] = true;
    }

    for (int i = 0; i < n; i++) {
        if (i)
            cout << ' ' << res[i];
        else
            cout << res[i];
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_--) {
        sol();
    }

    return 0;
}
