#include<bits/stdc++.h>
using namespace std;
const int N = 500 + 10, M = 10000 + 10, INF = 0x3f3f3f3f;

int n, m, k;
struct edge{
    int a, b, w;
} edge[M];
int dis[N], backup[N];

int bellman_ford(){
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    for(int i = 0; i < k; i++){
        memcpy(backup, dis, sizeof dis);
        for(int j = 0; j < m; j++){
            int a = edge[j].a, b = edge[j].b, w = edge[j].w;
            dis[b] = min(dis[b], backup[a] + w);
        }
    }

    if(dis[n] > INF / 2) return 0;
    else return dis[n];
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int a, b, k;
        cin >> a >> b >> k;
        edge[i] = {a, b, k};
    }


    int ans = bellman_ford();
    if(ans == 0) cout << "impossible";
    else cout << ans;

    return 0;
}