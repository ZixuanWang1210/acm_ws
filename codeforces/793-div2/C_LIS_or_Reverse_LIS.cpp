#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define all(x) x.begin() + 1, x.end()
// #define ll long long
// #define int long long

using namespace std;

void sol() {
    int n;
    cin >> n;
    map<int, int> mp;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[x]++;
        if (mp[x] <= 2) cnt++;
    }
    cout << ceil((double)cnt / 2) << endl;
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
