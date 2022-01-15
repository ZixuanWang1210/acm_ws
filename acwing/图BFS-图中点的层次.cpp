//https://www.acwing.com/solution/content/45573/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int N = 2 * maxn;

int n, m;
int h[maxn], ne[N], e[N], indx;
int dis[maxn];

void add(int a, int b){
    e[indx] = b, ne[indx] = h[a], h[a] = indx ++;
}

int bfs(){
    queue<int> q;
    q.push(1);
    memset(dis, -1, sizeof dis);
    dis[1] = 0;
    while(!q.empty()){
        int x = q.front();
        for(int i = h[x]; i != -1; i = ne[i]){
            if(dis[e[i]] == -1){
                dis[e[i]] = dis[x] + 1;
                q.push(e[i]);
            }
        }
        q.pop();
    }
    return dis[n];
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        add(a, b);
    }

    cout << bfs();

    return 0;
}