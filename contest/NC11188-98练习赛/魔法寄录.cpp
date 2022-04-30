#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

void sol() {
    int h, a, b;
    cin >> h >> a >> b;
    int tt = max(a, b * 3);
    tt *= 5;
    int res = (h + tt) / tt;
    // cout<<res;
    if (h == (res-1) * tt)
        cout << res - 1;
    else
        cout << res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int _ = 1;
    // cin>>_;
    while (_--) {
        sol();
    }

    return 0;
}
