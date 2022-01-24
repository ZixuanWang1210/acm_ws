#include <cmath>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 5 * 1e5 + 10;
// 2 ** 20 = 1048576
const int M = 20;
long long s[N], table[N][M];

void init(int n) {
    for (int i = 1; i <= n; i++) table[i][0] = i;
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            int x = table[i][j - 1], y = table[i + (1 << (j - 1))][j - 1];
            table[i][j] = s[x] > s[y] ? x : y;
        }
}

int query(int l, int r) {
    int k = log2(r - l + 1);
    int x = table[l][k], y = table[r - (1 << k) + 1][k];
    return s[x] > s[y] ? x : y;
}

// element(o, l, r)表示一组方案，左端点在o，右端点在[l, r]之间
struct element {
    int o, l, r, m;
    element() {}
    element(int o, int l, int r) : o(o), l(l), r(r), m(query(l, r)) {}
    friend bool operator < (const element& a, const element& b) {
        return s[a.m] - s[a.o - 1] < s[b.m] - s[b.o - 1];
    }
};

priority_queue<element> q;

int main() {
    int n, k, L, R;
    scanf("%d%d%d%d", &n, &k, &L, &R);
    // 前缀和
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &s[i]);
        s[i] += s[i - 1];
    }

    // 用ST树求解RMQ
    init(n);
    for (int i = 1; i <= n; i++)
        if (i + L - 1 <= n) 
            q.push(element(i, i + L - 1, min(i + R - 1, n)));

    long long ans = 0;
    while (k-- ) {
        element e = q.top(); q.pop();
        int o = e.o, l = e.l, r = e.r, m = e.m;

        ans += s[m] - s[o - 1];
        if (l != m) q.push(element(o, l, m - 1)); 
        if (m != r) q.push(element(o, m + 1, r));
    }
    printf("%lld\n", ans);

    return 0;
}
