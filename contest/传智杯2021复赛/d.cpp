#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define debug(x) cout << #x << ": -----> " << x << endl;

using namespace std;

int n, k, ans;
const int maxn = 1e8 + 10;
int v[maxn], s[maxn];

// bool check(int x) {
//     int res = 0;
//     int sum = 0;
//     for (int i = 1; i <= n; i++) {
//         sum += v[i];
//         if (sum > x) {
//             res++;
//             sum -= x;
//         }
//         if (i == n && sum!=0) res++;
//     }
//     if (res > k)
//         return false;
//     else
//         return true;
// }
bool check(int x) {
    int res = 1;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += v[i];
        if (sum > x) {
            res++;
            sum = v[i];
        }
        // if (i == n && sum!=0) res++;
    }
    if (res > k)
        return false;
    else
        return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int _max = -1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        v[i] = t * t;
        s[i] = s[i - 1] + v[i];
        _max = max(_max, v[i]);
    }

    int l = _max, r = 1e17;
    // cout<<r<<endl;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << l << endl;

    return 0;
}
