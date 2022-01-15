//https://www.acwing.com/solution/content/13602/
//https://www.bilibili.com/video/BV1q4411M7r9?from=search&seid=13329740267680383672&spm_id_from=333.337.0.0

#include<bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;

int g[maxn][maxn];
int dis[maxn];
int n, m;
bool st[maxn];

int dijkstra(){
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++){
            if(!st[j] && (t == -1 || dis[j] < dis[t])){
                t = j;
            }   
        }
        st[t] = true;
        for(int j = 1; j <= n; j++){
            dis[j] = min(dis[j], dis[t] + g[t][j]);
        }
    }
    
    if(dis[n] == 0x3f3f3f3f) return -1;
    return dis[n];
}

int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for(int i = 0; i < m; i++){
        int x, y, z; cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }

    cout << dijkstra() << endl;
    
    return 0;
}