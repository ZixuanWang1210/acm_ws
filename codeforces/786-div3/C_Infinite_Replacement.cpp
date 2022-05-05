#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int unsigned long long

using namespace std;

void sol() {
    string a, b;
    cin >> a >> b;
    if (b.length() == 1 && b == "a") {
        cout << 1 << endl;
        return;
    } else if (b.find('a') != b.npos) {
        cout << -1 << endl;
        return;
    } else {
        int siz = a.length();
        int ans = 1;
        // siz = 3;
        while (siz--) {
            ans *= 2;
        }
        cout << ans << endl;
        return;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int t=(1<<50);
    // cout<<t<<endl;
    int _ = 1;
    cin >> _;
    while (_--) {
        sol();
    }

    return 0;
}
