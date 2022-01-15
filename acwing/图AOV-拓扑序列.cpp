//https://www.acwing.com/solution/content/4732/

#include<bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10, N = 2 * M;

int h[M], e[N], ne[N], idx;
int top[M], d[M], cnt = 1;
int n, m;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool topsort(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(d[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int t = q.front();
        top[cnt++] = t;
        q.pop();
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            d[j]--;
            if(d[j] == 0) q.push(j);
        }
    }
    if(cnt < n) return 0;
    else return 1;
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--){
        int x, y;
        cin >> x >> y;
        add(x, y);
        d[y] ++;
    }

    if(topsort()){
        for(int i = 1; i <= n; i++) cout << top[i] << " ";
    }
    else cout << "-1";


    return 0;
}