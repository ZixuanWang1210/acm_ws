//https://www.acwing.com/solution/content/21910/

#include<bits/stdc++.h>
using namespace std;
typedef pair<int , int> pii;
const int maxn = 1.5e5 + 10;

int h[maxn], e[maxn], ne[maxn], v[maxn], idx;
int dis[maxn];
bool st[maxn];
int n, m;

void add(int a, int b, int c){
    e[idx] = b, v[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int dijkstra(){
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, 1});
    while(!heap.empty()){
        pii k = heap.top();
        heap.pop();
        int ver = k.second;
        
        if(st[ver]) continue;
        st[ver] = true;

        for(int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i];
            if(dis[j] > dis[ver] + v[i]){
                dis[j] = dis[ver] + v[i];
                heap.push({dis[j], j});
            }
        }
    }
    if(dis[n] == 0x3f3f3f3f) return -1;
    return dis[n];
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++){
        int x, y, z; cin >> x >> y >> z;
        add(x, y, z);
    }

    cout << dijkstra();

    return 0;
}