#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
using namespace std;
 
void sol() {
    int n;
    cin >> n;
    vector<int> ind[n + 1], a(n);
    int mx = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
        mx = max(mx, mp[a[i]]);
    }
    vector<int> b(a);
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        ind[b[i]].push_back(b[(i + mx) % n]);
    }
    for (int i = 0; i < n; i++) {
        cout << ind[a[i]].back() << " ";
        ind[a[i]].pop_back();
    }
    cout << endl;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int _;
    cin >> _;
    while (_--) {
        sol();
    }
 
    return 0;
}