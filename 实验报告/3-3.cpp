#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
int dp[maxn][maxn];
int n;

int main() {
    cin >> n;
    dp[1][1] = 1;
    cout << 1 << endl;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
