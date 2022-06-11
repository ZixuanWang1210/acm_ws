#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define all(x) x.begin() + 1, x.end()
#define _all(x) x.begin(), x.end()
// #define ll long long
// #define int long long

using namespace std;

void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    map<int, int> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[a[i]]++;
    }
    int mex;
    int t = k;
    for (int i = 0;; i++) {
        if (!s.count(i)) {
            if (t)
                t--;
            else {
                mex = i;
                break;
            }
        }
    }
    set<pair<int, int>> ss;
    for (auto [x, y] : s)
        if (x > mex) ss.insert({y, x});

    while (ss.size() && k >= ss.begin()->first) {
        k -= ss.begin()->first;
        ss.erase(ss.begin());
    }
    cout << ss.size() << '\n';
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
