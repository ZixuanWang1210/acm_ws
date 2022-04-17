#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long
using namespace std;

int a[100000];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            int cnt = 0;
            for (int j = 1; j <= n; j++)
                if (a[j] >> i & 1) cnt++;
            if (cnt > n - cnt) res += 1 << i;
        }
        cout << res << '\n';
    }
    return 0;

    return 0;
}
