#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
typedef long long ll;
using namespace std;

const int maxn = 1e6+10;
vector<int> a[maxn], b[maxn];
set<int> st;
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            st.insert(x);
            a[x].push_back(i);
            b[x].push_back(j);
        }
    }
    ll ans = 0;
    for (auto &x : st) {
        sort(a[x].begin(), a[x].end());
        sort(b[x].begin(), b[x].end());
        for (int i = 0; i < a[x].size(); i++) {
            int low = i;
            int high = a[x].size() - i - 1;
            ans += 1ll * (low - high) * (a[x][i] + b[x][i]);
        }
    }
    cout << ans << endl;

    return 0;
}
