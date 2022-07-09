#include<bits/stdc++.h>
#include<unordered_map>
#define mem(a,b) memset(a,b,sizeof a)
#define cinios (ios::sync_with_stdio(false),cin.tie(0),cout.tie(0))
#define sca scanf
#define pri printf
#define forr(a,b,c) for(int a=b;a<=c;a++)
#define rfor(a,b,c) for(int a=b;a>=c;a--)
#define endl "\n"
//[博客地址]：https://blog.csdn.net/weixin_51797626?t=1
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

double DNF = 1e17;
const int N = 210, M = 40010, MM = N;
int INF = 0x3f3f3f3f, mod = 998244353;
ll LNF = 0x3f3f3f3f3f3f3f3f;
int n, m, k, T, S, D;
int h[N], e[M], ne[M], f[M], idx;
int dep[N], cur[N], aa[N];
int s, t, tot;

void add(int a, int b, int c, int d) {
    e[idx] = b, f[idx] = d - c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
}

bool bfs() {
    queue<int> q;
    q.push(S);
    mem(dep, -1);
    dep[S] = 0, cur[S] = h[S];
    while (q.size())
    {
        int t = q.front();
        q.pop();
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dep[j] == -1 && f[i]) {
                dep[j] = dep[t] + 1;
                cur[j] = h[j];
                if (j == T)return true;
                q.push(j);
            }
        }
    }
    return false;
}

int find(int u, int limit) {
    if (u == T)return limit;
    int flow = 0;
    for (int i = cur[u]; ~i && flow < limit; i = ne[i]) {
        cur[u] = i;
        int j = e[i];
        if (dep[j] == dep[u] + 1 && f[i]) {
            int t = find(j, min(f[i], limit - flow));
            if (!t)dep[j] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t;
        }
    }
    return flow;
}

int dinic() {
    int r = 0, flow;
    while (bfs())while (flow = find(S, INF))r += flow;
    return r;
}

int main() {
    cinios;

    cin >> n >> m >> s >> t;
    mem(h, -1);
    S = n + 1, T = S + 1;

    forr(i, 1, m) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add(a, b, c, d);
        aa[a] -= c, aa[b] += c;
        //bug —— aa[a] += c, aa[b] -= c;
        //注意这里 c 的定义是少流入和少流出
    }

    //因为有上下界所以建虚拟源点S、T补流
    forr(i, 1, n)
        if (aa[i] > 0)add(S, i, 0, aa[i]), tot += aa[i];
        else if (aa[i] < 0)add(i, T, 0, -aa[i]);

    add(t, s, 0, INF);//但是原图有自带的源汇点，源汇点不保证流量守恒（其他点都保证）
    //所以需要补一条 t——s 的满容量边，让原图流量守恒
    int tt=dinic();
    cout<<tot<<' '<<tt<<endl;
    if (tt < tot)cout << "No Solution";
    else {
        int res = f[idx - 1];
        cout<<res<<endl;
        S = s, T = t;
        f[idx - 1] = f[idx - 2] = 0;
        cout << res + dinic();
    }

    return 0;
}