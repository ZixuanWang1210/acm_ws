#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 1e300
#define pii pair<int, int>
#define pdd pair<double, double>
#define all(x) x.begin() + 1, x.end()
#define _all(x) x.begin(), x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<pii> v;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    if (n < 5) {
        cout << "NO" << endl;
        return;
    }
    bool ok = false;
    pii a, b, c, d, e;
    a = v[0], b = v[1], c = v[2], d = v[3];
    for (int i = 4; i < n; i++) {
        e = v[i];
        set<pii> st;
        // double k1 = (e.second - a.second == 0) ? inf : (e.first - a.first) / (e.second - a.second);
        // double k2 = (e.second - b.second == 0) ? inf : (e.first - b.first) / (e.second - b.second);
        // double k3 = (e.second - c.second == 0) ? inf : (e.first - c.first) / (e.second - c.second);
        // double k4 = (e.second - d.second == 0) ? inf : (e.first - d.first) / (e.second - d.second);
        // int k1=(e.first - a.first) / (e.second - a.second)
        st.insert({(e.first - a.first)/(__gcd(e.first - a.first,e.second - a.second)),(e.second - a.second)/(__gcd(e.first - a.first,e.second - a.second))});
        st.insert({(e.first - b.first)/(__gcd(e.first - b.first,e.second - b.second)),(e.second - b.second)/(__gcd(e.first - b.first,e.second - b.second))});
        st.insert({(e.first - c.first)/(__gcd(e.first - c.first,e.second - c.second)),(e.second - c.second)/(__gcd(e.first - c.first,e.second - c.second))});
        st.insert({(e.first - d.first)/(__gcd(e.first - d.first,e.second - d.second)),(e.second - d.second)/(__gcd(e.first - d.first,e.second - d.second))});
        if (st.size()==1)
            continue;
        else {
            ok = true;
            break;
        }
    }
    if (!ok) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    pii res[6];
    res[1] = a, res[2] = b, res[3] = c, res[4] = d, res[5] = e;
    for (int i = 1; i <= 5; i++) {
        pii ee = res[i];
        set<pii> cmp;
        for (int j = 1; j <= 5; j++) {
            if (i == j) continue;
            int dx = ee.first - res[j].first, dy = ee.second - res[j].second;
            cmp.insert({dx / abs(__gcd(dx, dy)), dy / abs(__gcd(dx, dy))});
        }
        int ans = 0;
        if (cmp.size() == 4) {
            cout << ee.first << ' ' << ee.second << endl;
            for (int j = 1; j <= 5; j++) {
                if (i == j) continue;
                cout << res[j].first << ' ' << res[j].second << endl;
            }
            return;
        }
    }
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
