#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[20];

int get(int x) {
    int res = 0;
    while (x) {
        if (x & 1) res++;
        x >>= 1;
    }
    return res;
}

void biao() {
    a[1] = 1;
    a[0] = 0;
    for (int i = 2; i <= 15; i++) {
        a[i] = a[i - 1] * i;
        // cout<<a[i]<<' ';
    }
}

void sol() {
    int x;
    cin >> x;
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < (1 << 16); i++) {

        int temp = 0, cnt = 0;
        for (int j = 0; j < 16; j++) {
            if (i & (1 << j)) {
                temp += a[j];
                cnt++;
            }
        }
        if (temp > x)
            continue;
        else {
            int res = cnt + get(x - temp);
            ans = min(res, ans);
        }
    }
    cout << ans << endl;
    return;
}

signed main() {
    biao();
    int t;
    cin >> t;
    while (t--) {
        sol();
    }

    return 0;
}