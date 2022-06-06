#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
// typedef long long int;
// typedef unsigned long long ull;
#define int long long

using namespace std;

void sol() {
    int n, x;
    cin >> n >> x;
    queue<pair<int, int>> q;
    q.push({x, 0});
    map<int, int> mp;
    mp[x] = 0;
    while (!q.empty()) {
        auto [t, cnt] = q.front();
        q.pop();
        if (to_string(t).size() > n) continue;
        if (to_string(t).size() == n) {
            cout << cnt << '\n';
            return;
        }
        set<int> s;
        for (auto it : to_string(t))
            if (it != '0') s.insert(it - '0');
        for (auto i : s) {
            if (mp.count(t * i) == 0) {
                mp[t * i] = cnt + 1;
                q.push({t * i, cnt + 1});
            }
        }
    }
    cout << -1 << '\n';
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _ = 1;
    // cin>>_;2
    while (_--) {
        sol();
    }

    return 0;
}
