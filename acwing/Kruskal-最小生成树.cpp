//https://www.acwing.com/solution/content/42480/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10, INF = 0x3f3f3f3f;

struct Edge{
    int u, v, w;
    bool operator<(const Edge &e) const{
        return w < e.w;
    }
}edge[maxn];

int n, m;
int p[maxn];

int find(int x){
    if(p[x] != x) p[x] =find(p[x]);
    return p[x];
}

int kruskal(){
    sort(edge, edge + m);

    for(int i = 1; i <= n; i++){
        p[i] = i;
    }

    int res = 0, cnt = 0;
    for(int i = 0; i < m; i++){
        int u = edge[i].u, v= edge[i].v, w = edge[i].w;
        u = find(u), v = find(v);
        if(u != v){
            p[u] = v;
            res += w;
            cnt++;
        }
    }
    if(cnt < n - 1) return INF;
    else return res;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w;
        edge[i] = {a, b, w};
    }

    int t = kruskal();

    if(t == INF) cout << "impossible";
    else cout << t << endl;

    return 0;
}
