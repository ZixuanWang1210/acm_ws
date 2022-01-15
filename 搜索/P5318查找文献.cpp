#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
int n, m;
vector<int> ve[maxn];
bool vis[maxn];
queue<int> q;

int bfs(int x){
    memset(vis, false, sizeof(vis));
    vis[x] = true;
    q.push(x);
    while(!q.empty()){
        int top = q.front();
        cout << top<<" ";
        for(int i = 0; i < ve[top].size(); i++){
            if(!vis[ve[top][i]]){
                vis[ve[top][i]] = true;
                q.push(ve[top][i]);
            }
        }
        q.pop();
    }
}

int dfs(int x, int now){
    vis[x] = true;
    cout << x << " ";
    if(now == n) return 0;
    else{
        for(int i = 0; i < ve[x].size(); i++){
            if(!vis[ve[x][i]]) dfs(ve[x][i], now+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        ve[u].push_back(v);
    }
    for(int i = 0; i < n; i++){
        sort(ve[i].begin(), ve[i].end());
    }
    dfs(1, 0);
    cout << endl;
    memset(vis, false, sizeof(vis));
    bfs(1);
    
    return 0;
}
