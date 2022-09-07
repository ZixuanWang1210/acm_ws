#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = 5210, INF = 1e8;

int n, S, T;
int h[N], e[M], f[M], w[M], ne[M], idx;
int q[N], d[N], pre[N], incf[N];
bool st[N];

void add(int a, int b, int c, int d)
{
    e[idx] = b, f[idx] = c, w[idx] = d, ne[idx] = h[a], h[a] = idx ++ ;
    e[idx] = a, f[idx] = 0, w[idx] = -d, ne[idx] = h[b], h[b] = idx ++ ;
}

bool spfa()
{
    int hh = 0, tt = 1;
    memset(d, 0x3f, sizeof d);
    memset(incf, 0, sizeof incf);
    q[0] = S, d[S] = 0, incf[S] = INF;
    while (hh != tt)
    {
        int t = q[hh ++ ];
        if (hh == N) hh = 0;
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i])
        {
            int ver = e[i];
            if (f[i] && d[ver] > d[t] + w[i])
            {
                d[ver] = d[t] + w[i];
                pre[ver] = i;
                incf[ver] = min(f[i], incf[t]);
                if (!st[ver])
                {
                    q[tt ++ ] = ver;
                    if (tt == N) tt = 0;
                    st[ver] = true;
                }
            }
        }
    }
    return incf[T] > 0;
}

int EK()
{
    int cost = 0;
    while (spfa())
    {
        int t = incf[T];
        cost += t * d[T];
        for (int i = T; i != S; i = e[pre[i] ^ 1])
        {
            f[pre[i]] -= t;
            f[pre[i] ^ 1] += t;
        }
    }
    return cost;
}

int main()
{
    scanf("%d", &n);
    S = 0, T = n * 2 + 1;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i ++ )
    {
        add(S, i, 1, 0);
        add(n + i, T, 1, 0);
    }
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
        {
            int c;
            scanf("%d", &c);
            add(i, n + j, 1, c);
        }

    printf("%d\n", EK());

    for (int i = 0; i < idx; i += 2)
    {
        f[i] += f[i ^ 1], f[i ^ 1] = 0;
        w[i] = -w[i], w[i ^ 1] = -w[i ^ 1];
    }
    printf("%d\n", -EK());

    return 0;
}