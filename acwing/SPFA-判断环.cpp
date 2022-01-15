//https://www.acwing.com/solution/content/6336/


#include<bits/stdc++.h>
using namespace std;
const int maxn = 5;

int h[maxn], e[maxn], ne[maxn], w[maxn], idx;
int dis[maxn], cnt[maxn], st[maxn];
int n, m;

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa(){
    // dis[1] = 0;

    queue<int> q;
    for(int i = 1; i <= n; i++) q.push(i), st[i] = true;
    while(!q.empty()){
        int t = q.front(); q.pop(); st[t] = false;
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(dis[j] > dis[t] + w[i]){
                dis[j] = dis[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n) return true;
                if(!st[j]){
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
    return false;
}


int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i++){
        int x, y, z; cin >> x >> y >> z;
        add(x, y, z);
    }
    
    if(spfa()) puts("Yes");
    else puts("No");
    //cout << spfa() ? puts("Yes") : puts("No");

    return 0;
}