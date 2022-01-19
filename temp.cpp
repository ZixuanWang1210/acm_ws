#include <bits/stdc++.h>
using namespace std;

int m, n1, n2;
const int M = 1e5 + 10, N = 510;
int e[M], ne[M], h[N], idx;
bool st[N];
int match[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool find(int x){
    for(int i = h[x]; i != -1; i = ne[i]){
        int j = e[i];
        if(st[j]) continue;
        st[j] = true;

        if(match[j] == 0 || find(match[j])){
            match[j] = x;
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i ++){
        int u, v; cin >> u >> v;
        add(u, v);
    }

    int cnt = 0;
    for(int i = 1; i <= n1; i ++){
        memset(st, false, sizeof st);
        if(find(i)) cnt ++;
    }
    
    cout << cnt;

    return 0;
}
