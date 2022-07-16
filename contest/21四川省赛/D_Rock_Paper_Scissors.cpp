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
void sol() {
    int b[4], d[4];
    cin >> b[1] >> b[2] >> b[3];
    cin >> d[1] >> d[2] >> d[3];
    int cnt = 0;
    if (b[1]) {
        if (d[2] && b[1]) {
            int tt = min(d[2], b[1]);
            cnt += tt;
            d[2] -= tt;
            b[1] -= tt;
        }
        if (d[1] && b[1]) {
            int tt = min(d[1], b[1]);
            d[1] -= tt;
            b[1] -= tt;
        }
        if (d[3] && b[1]) {
            int tt = min(d[3], b[1]);
            cnt -= tt;
            b[1] -= tt;
            d[3] -= tt;
        }
    }
    if (b[2]) {
        if (d[3] && b[2]) {
            int tt = min(d[3], b[2]);
            cnt += tt;
            d[3] -= tt;
            b[2] -= tt;
        }
        if (d[2] && b[2]) {
            int tt = min(d[2], b[2]);
            d[2] -= tt;
            b[2] -= tt;
        }
        if (d[1] && b[2]) {
            int tt = min(d[1], b[2]);
            cnt -= tt;
            d[1] -= tt;
            b[2] -= tt;
        }
    }
    if (b[3]) {
        if (d[1] && b[3]) {
            int tt = min(d[1], b[3]);
            cnt += tt;
            d[1] -= tt;
            b[3] -= tt;
        }
        if (d[3] && b[3]) {
            int tt = min(d[3], b[3]);
            d[3] -= tt;
            b[3] -= tt;
        }
        if (b[3] && d[2]) {
            int tt = min(b[3], d[2]);
            cnt -= tt;
            b[3] -= tt;
            d[2] -= tt;
        }
    }
    cout << cnt << endl;
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
