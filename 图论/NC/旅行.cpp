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
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int h[N], ne[N], e[N], idx, w[N];

int dist[N];
bool st[N];

int t, n, m;

void add(int a, int b, int c) {
    w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dj(int s) {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, s});

    int ans1 = 0;
    int ans2 = 0;

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;
        st[ver] = true;

        ans2 = max(ans2, dist[ver]);
        if (ans2 > ans1) swap(ans2, ans1);

        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if (ans2 == 0) return -1;
    return ans1 + ans2;
}

int main() {
    cin >> t;
    while (t--) {
        memset(h, -1, sizeof h);
        cin >> n >> m;
        while (m--) {
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c);
            add(b, a, c);
        }
        int ans = -1;
        for (int i = 1; i <= n; i++) ans = max(ans, dj(i));
        cout << ans << endl;
    }
    return 0;
}