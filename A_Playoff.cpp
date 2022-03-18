#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol() {
    int n;
    cin >> n;
    long long base = 1;
    for (int i = 1; i <= n; i++) {
        base *= 2;
    }
    cout << base - 1<<endl;
}

int main() {
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
