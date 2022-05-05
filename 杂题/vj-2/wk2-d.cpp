#include <bits/stdc++.h>
#define endl "\n"
#define debug(v) cout << #v << ": -----> " << v << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;
const int max = 1100;

void sol() {
    int n;
    cin >> n;
    if (n < 4) {
        cout << -1 << endl;
        return;
    } else if (n == 4) {
        cout << "2 4 1 3" << endl;
        return;
    }
    int cnt;
    cnt = 0;
    vector<int> v(n + 1);
    if (n & 1) {
        for (int i = 1; i <= n; i += 2) v[++cnt] = i;
        v[++cnt] = n - 3, v[++cnt] = n - 1;
        for (int i = n - 5; i; i -= 2) v[++cnt] = i;
    } else {
        for (int i = 1; i <= n; i += 2) v[++cnt] = i;
        v[++cnt] = n - 4, v[++cnt] = n, v[++cnt] = n - 2;
        for (int i = n - 6; i; i -= 2) v[++cnt] = i;
    }
    for (int i = 1; i <= n; i++) cout << v[i] << " ";
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int _ = 1;
    cin >> _;
    while (_--) {
        sol();
    }

    return 0;
}
