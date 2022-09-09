#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;
const int maxn=100;
char mp[maxn][maxn];
int n,m;
int id_r[maxn][maxn],id_c[maxn][maxn];
template<class T>
struct Flow {
    const int n;
    struct Edge {
        int to;
        T cap;
        Edge(int to, T cap) : to(to), cap(cap) {}
    };
    std::vector<Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<int> cur, h;
    Flow(int n) : n(n), g(n) {}
    
    bool bfs(int s, int t) {
        h.assign(n, -1);
        std::queue<int> que;
        h[s] = 0;
        que.push(s);
        while (!que.empty()) {
            const int u = que.front();
            que.pop();
            for (int i : g[u]) {
                auto [v, c] = e[i];
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t) {
                        return true;
                    }
                    que.push(v);
                }
            }
        }
        return false;
    }
    
    T dfs(int u, int t, T f) {
        if (u == t) {
            return f;
        }
        auto r = f;
        for (int &i = cur[u]; i < int(g[u].size()); ++i) {
            const int j = g[u][i];
            auto [v, c] = e[j];
            if (c > 0 && h[v] == h[u] + 1) {
                auto a = dfs(v, t, std::min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0) {
                    return f;
                }
            }
        }
        return f - r;
    }
    void addEdge(int u, int v, T c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    T maxFlow(int s, int t) {
        T ans = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, std::numeric_limits<T>::max());
        }
        return ans;
    }
};

void sol(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char t; cin>>t;
            mp[i][j]=t;
        }
    }

    int t=0;
    int cnt_r=0,cnt_c=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='#') continue;
            if((j==1||(mp[i][j-1]=='#'))) t++;
            id_r[i][j]=t;
            cnt_r=max(cnt_r,id_r[i][j]);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(mp[j][i]=='#') continue;
            if((j==1||(mp[j-1][i]=='#'))) t++;
            id_c[j][i]=t;
            cnt_c=max(cnt_c,id_c[j][i]);
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<id_r[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<id_c[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int S=0,T=2*n*n+8;
    Flow<int> plt(2*n*n+10);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='*') plt.addEdge(id_r[i][j],id_c[i][j],1);
        }
    }

    for(int i=1;i<=cnt_r;i++){
        plt.addEdge(S,i,1);
    }
    for(int i=cnt_r+1;i<=cnt_c;i++){
        plt.addEdge(i,T,1);
    }

    cout<<plt.maxFlow(S,T)<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
