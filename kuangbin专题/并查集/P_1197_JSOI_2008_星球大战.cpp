#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 4 * 100010;

int n, m;
int tot;

bool flag[N];

int p[N];

vector <int> u[N];
int kk[N];
int ans[N];

int find(int x)
{
    if(p[x] != x)
        p[x] = find(p[x]);

    return p[x];
}

void meger(int x, int y)
{
    int px = find(x);
    int py = find(y);

    if(px != py)    //说明两个点不在一个连通块中
    {
        tot --;     //维护有多少个连通块
        p[px] = py;
    }
}

int main()
{
    scanf("%d%d",&n,&m);

    for(int i = 0; i < n; i ++) p[i] = i;

    for(int i = 0; i < m; i ++)
    {
        int x, y;
        cin >> x >> y;
        u[x].push_back(y);
        u[y].push_back(x);
    }

    int k;
    cin >> k;
    for(int i = 1; i <= k; i ++) cin >> kk[i], flag[kk[i]] = true;

    tot = n - k;

    for(int i = 0; i < n; i ++)
    {
        if(flag[i] == false)  //将没有被摧毁的点合并
        {
            for(int j = 0; j < u[i].size(); j ++ )
            {
                int v = u[i][j];
                if(flag[v] == true) continue;
                meger(i, v);  //合并
            }
        }
    }

    //1 6 3 5 7
    for(int i = k; i >= 1; i --)
    {
        ans[i] = tot;
        tot ++;
        flag[kk[i]] = false;
        for(int j = 0; j < u[kk[i]].size(); j ++ )
        {
            int v = u[kk[i]][j];
            if(flag[v]) continue;
            meger(kk[i], v);
        }
    }

    ans[0] = tot;
    for(int i = 0; i <= k; i ++)
        cout << ans[i] << endl;

    return 0;
}