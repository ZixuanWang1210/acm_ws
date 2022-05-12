#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol() {
    int n;
    cin >> n;
    bool flag1 = 0, flag2 = 0;
    int num = 0;
    int tmp;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp == 0)
            flag1 = 1;
        else {
            if (m[tmp]) flag2 = 1;
            m[tmp] = 1;
            num++;
        }
    }
    if (flag1)
        cout << num << endl;
    else {
        if (flag2)
            cout << n << endl;
        else
            cout << n + 1 << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int _ = 1;
    cin >> _;
    while (_--) {
        sol();
    }

    return 0;
}
