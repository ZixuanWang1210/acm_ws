#include <bits/stdc++.h>
using namespace std;

int a, b, k;
vector<int> res;

void dfs(int a, int u) {
    if (u == k + 1) return;
    res.push_back(a / b);
    dfs(a % b * 10, u + 1);
}

signed main() {
    cin >> a >> b >> k;
    int t1 = a / b;
    cout << t1 << '.';
    a = a % b;
    dfs(a * 10, 0);
    if (res.back() >= 5) {
        res[res.size() - 2]++;
    }

    for (int i = 0; i + 1 < res.size(); i++) cout << res[i];
    return 0;
}