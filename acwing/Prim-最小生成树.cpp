//https://www.acwing.com/solution/content/38312/
//https://www.acwing.com/solution/content/34197/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

int mp[510][510];
int n, m;
int dis[510], pre[510]; //pre前驱点的idx
bool st[510];


int prim(){
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    int res = 0;

    for(int i = 0; i < n; i++){ //每次循环选一个点加入生成树, 第一个点特判
        int t = -1;
        for(int j = 1; j <= n; j++){ //找到不在集合中且离集合最近的点, idx为t
            if(!st[j] && (t == -1 || dis[j] < dis[t]))
                t = j;
        }

        if(i && dis[t] == 0x3f3f3f3f) return 0x3f3f3f3f; //有点无法全部联通

        st[t] = true; //选择该点
        if(i) res += dis[t]; //累加距离
        for(int i = 1; i <= n; i++){
            dis[i] = min(dis[i], mp[t][i]);
        }
    }

    return res;
}

int main(){

    cin >> n >> m;
    memset(mp, 0x3f, sizeof mp);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        mp[u][v] = mp[v][u] = min(mp[u][v], w);
    }

    int ans = prim();

    if(ans == 0x3f3f3f3f) cout << "impossible";
    else cout << ans;

    return 0;
}