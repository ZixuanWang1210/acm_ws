#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define all(x) x.begin() + 1, x.end()
#define _all(x) x.begin(), x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

int p = 2e18;

int q_mi(int m, int k) {
    int res = 1 % p, t = m;
    while (k) {
        if (k & 1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
        if (q_mi(10, i) > n) {
            cout << n - q_mi(10, i - 1) << endl;;
            return;
        }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}