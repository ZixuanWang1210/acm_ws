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

void sol() {
    
    map<int, int> vis;
    map<int, int> last;
    map<int, set<int>> del;
    map<int, vector<int>> change;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        char op;
        int x;
        cin >> op >> x;
        if (op == '+') {
            vis[x] = 1;
            for (int y : change[x]) {
                del[y].erase(x);
            }
        } else if (op == '-') {
            vis[x] = 0;
            for (int y : change[x]) {
                del[y].insert(x);
            }
        } else {
            if (!last.count(x)) last[x] = x;
            if (del[x].size()) {
                cout << *del[x].begin() << endl;
            } else {
                while (vis[last[x]]) {
                    change[last[x]].push_back(x);
                    last[x] += x;
                }
                cout << last[x] << endl;
            }
        }
    }
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
