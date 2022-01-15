//https://www.acwing.com/solution/content/3734/
//https://www.acwing.com/solution/content/9306/
//https://www.acwing.com/solution/content/21057/

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;

int h[maxn], e[maxn], ne[maxn], w[maxn], idx;
int dis[maxn];
bool st[maxn];
int n, m;

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int spfa(){
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;
    while(!q.empty()){
        int t = q.front(); q.pop(); st[t] = false;
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(dis[j] > dis[t] + w[i]){ //注意w的idx为i！！！
                dis[j] = dis[t] + w[i];
                if(!st[j]){
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }

    return dis[n];
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++){
        int x, y, z; cin >> x >> y >> z;
        add(x, y, z);
    }

    int ans = spfa();
    
    if(ans == 0x3f3f3f3f) cout << "impossible";
    else cout << ans;
    
    return 0;
}