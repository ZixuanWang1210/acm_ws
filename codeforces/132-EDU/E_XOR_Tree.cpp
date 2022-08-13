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

const int N = 2e5 + 10;
int a[N], ans;
int f[N];
vector<int> v[N];
unordered_set<int> s[N];
void dfs(int x, int fa) {
    f[x] = f[fa] ^ a[x];
    s[x].insert(f[x]);
    bool flag = 0;
    for (int i = 0; i < v[x].size(); i++) {
        int t = v[x][i];
        if (t == fa) continue;
        dfs(t, x);
        if (s[x].size() < s[t].size()) swap(s[x], s[t]);
        for (int y : s[t])
            if (s[x].find(y ^ a[x]) != s[x].end()) flag = 1;
        for (int y : s[t]) s[x].insert(y);
    }
    if (flag) ans++, s[x].clear();
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y), v[y].push_back(x);
    }
    dfs(1, 0);
    cout << ans << endl;
}
