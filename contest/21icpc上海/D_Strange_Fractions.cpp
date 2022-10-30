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

bool check(ll n) {   // 判断n是否为平方数
    ll tmp = floor(sqrt(n) + 0.5);
    return tmp * tmp == n;
}

void sol() {
    int p, q;
    cin >> p >> q;

    if ((ll)p * p < (ll)4 * q * q) {   // 无解
        cout << "0 0" << endl;
        return;
    }

    ll tmp = (ll)p * p - (ll)4 * q * q;   // p^2-4q^2
    if (!check(tmp)) {                    // 无解
        cout << "0 0" << endl;
        return;
    }

    tmp = sqrt(tmp);
    int d = __gcd(p + tmp, 1ll * 2 * q);
    cout << (p + tmp) / d << ' ' << (2 * q) / d << endl;
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
