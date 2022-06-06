#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 200005;

int a[N], l[N], r[N];
LL s[N];

int d1[N][20];   //最大
int d2[N][20];   //最小
void RMQ_init(int n) {
    for (int i = 0; i <= n; i++) {
        d1[i][0] = d2[i][0] = i;
    }
    for (int j = 1; 1 << j <= n + 1; j++) {
        for (int i = 0; i + (1 << j) - 1 <= n; i++) {
            int x = d1[i][j - 1], y = d1[i + (1 << j - 1)][j - 1];
            d1[i][j] = s[x] >= s[y] ? x : y;
            x = d2[i][j - 1], y = d2[i + (1 << j - 1)][j - 1];
            d2[i][j] = s[x] <= s[y] ? x : y;
        }
    }
}
int RMQ1(int L, int R) {
    int k = log2(R - L + 1);
    int x = d1[L][k], y = d1[R - (1 << k) + 1][k];
    return s[x] >= s[y] ? s[x] : s[y];
}
int RMQ2(int L, int R) {
    int k = log2(R - L + 1);
    int x = d2[L][k], y = d2[R - (1 << k) + 1][k];
    return s[x] <= s[y] ? s[x] : s[y];
}
int main() {
    int _;
    scanf("%d", &_);
    while (_--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            s[i] = s[i - 1] + a[i];
        }
        RMQ_init(n);
        a[0] = a[n + 1] = INF;
        for (int i = 1; i <= n; i++) {
            l[i] = i;
            while (a[i] >= a[l[i] - 1]) l[i] = l[l[i] - 1];
        }
        for (int i = n; i >= 1; i--) {
            r[i] = i;
            while (a[i] >= a[r[i] + 1]) r[i] = r[r[i] + 1];
        }
        for (int i = 1; i <= n; i++) cout << l[i] << " ";
        //    for (int i = n;i >=1;i--) cout << r[i] << " ";
        int ok = 1;
        for (int i = 1; i <= n; i++) {
            LL t = RMQ1(i, r[i]) - RMQ2(l[i] - 1, i - 1);
            // printf("%d %d\n", RMQ1(i, r[i]), RMQ2(l[i] - 1, i - 1));
            if (a[i] < t) ok = 0;
        }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}
