#include<bits/stdc++.h>
// #define int long long
#define LL long long
using namespace std;


const int N=300005,M=N<<1;
int n,k;
int h[N],e[M],ne[M],idx;
int color[N];
bool ok = false;
bool has_father[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}


void dfs(int u, int count){
    if(ok) return;
    if(count==k){
        for(int i=1; i<=n; i++){
            if(color[i]) cout << i << ' ';
        }
        ok = true;
        return;
    }

    for(int i=h[u]; ~i; i=ne[i]){
        int v=e[i];
        if(color[u]==1 && color[v]==1) continue;

        color[1] = 1;
        dfs(v, u, count+1);
        color[1] = 0;
        dfs(v, u, count);

    }

}

signed main(){
    memset(h, -1, sizeof h);
    memset(color, -1, sizeof color);
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        int a,b;
        cin >> a >> b;
        add(a,b);
        has_father[b] = true;
    }    
    int root=1;
    while(has_father[root]) root++;
    dfs(root, 0);
    memset(color, -1, sizeof color);
    if(!ok) {
        color[1] = 1;
        dfs(1, -1, 1);
    }
    if(!ok) cout << -1;

    return 0;
}