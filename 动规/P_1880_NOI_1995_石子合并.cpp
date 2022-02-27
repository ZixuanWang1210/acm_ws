#include<bits/stdc++.h>
using namespace std;
const int N = 307;

int a[N], s[N];
int f[N][N],f2[N][N];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] += s[i - 1] + a[i];
    }
    for (int len = 1; len < n; len ++) { // len表示i和j堆下标的差值
        for (int i = 1; i + len <= n; i ++) {
            int j = i + len;
            f[i][j] = 1e8;
            f2[i][j] = -1e8;
            for (int k = i; k <= j - 1; k ++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
                f2[i][j] = max(f2[i][j], f2[i][k] + f2[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }
    cout << f[1][n] << endl << f2[1][n] <<endl;
    return 0;
}