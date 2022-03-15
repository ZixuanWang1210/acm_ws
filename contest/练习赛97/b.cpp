#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n;
const int maxn = 1e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<int> v(2 * n);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    cout << 2 * *max_element(v.begin() + 1, v.begin() + 1 + n);

    return 0;
}
