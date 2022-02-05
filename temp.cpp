#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int N = 2000;
int n, m;
int e[N], ne[N], h[N], idx;
int dis[N], w[N];
int st[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int spfa() {
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dis[j] > dis[t] + 1) {
                dis[j] = dis[t] + 1;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return dis[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    string s;
    getline(cin, s);
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i++) {
        getline(cin, s);
        vector<int> v;
        stringstream ssin(s);
        int tt;
        while (ssin >> tt) v.push_back(tt);
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                add(v[i], v[j]);
            }
        }
    }

    spfa();

    int ans = spfa();
    if (ans == 0x3f3f3f3f)
        cout << "NO" << endl;
    else
        cout << ans - 1 << endl;

    return 0;
}
