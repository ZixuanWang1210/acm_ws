#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define all(x) x.begin() + 1, x.end()
#define _all(x) x.begin(), x.end()
#define mod 1000000007
// #define ll long long
#define int long long

using namespace std;

int n, m;
const int maxn = 2e5 + 10;
int a[maxn], d1[maxn], d2[maxn], d3[maxn], d4[maxn];

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++) {
        a[i] = d1[i] = d2[i] = d3[i] = d4[i] = 0;
    }

    while (m--) {
        int typ, pos;
        cin >> typ >> pos;
        if (typ == 1) {
            a[pos]++;
            a[pos] %= mod;
        } else if (typ == 2) {
            d1[pos]++;
            d1[pos] %= mod;
        } else {
            d3[pos]++;
            d3[pos] %= mod;
            d3[pos + 1]++;
            d3[pos + 1] %= mod;
        }
    }

    for (int i = 1; i <= n; i++) {
        d2[i] += d2[i - 1] + d3[i];
        d2[i] %= mod;
    }
    for (int i = 1; i <= n; i++) {
        d1[i] += d1[i - 1] + d2[i];
        d1[i] %= mod;
    }
    for (int i = 1; i <= n; i++) {
        a[i] += a[i - 1] + d1[i];
        a[i] %= mod;
        cout << a[i] << ' ';
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
