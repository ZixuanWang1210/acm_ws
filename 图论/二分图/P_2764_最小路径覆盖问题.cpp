#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
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

int n,m;
const int maxn=1e4+10;
int p[maxn];
int find(int x){
    if(x!=p[x]) return p[x]=find(p[x]);
    else return x;
}
bool st[maxn];
int pre[maxn];
int ans[maxn];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    int S=0,T=2*n+1;
    Flow<int> plt(2*n+2);
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        plt.addEdge(u,n+v,1);
    }
    for(int i=1;i<=n;i++){
        plt.addEdge(S,i,1);
        plt.addEdge(i+n,T,1);
    }

    int res=plt.maxFlow(S,T);
    res=n-res;
    memset(pre,-1,sizeof pre);

    // 最小路径覆盖求方案
    for(int i=1;i<=n;i++){
        for(int j=0;j<plt.g[i].size();j++){
            int jj=plt.g[i][j];
            int v=plt.e[jj].to,f=plt.e[jj^1].cap;
            // cout<<jj<<" "<<(jj^1)<<endl;
            // if(i==1) cout<<jj<<' '<<v<<' '<<(f)<<endl;
            if(f>0&&v){
                pre[v-n]=i;
                ans[i]=v-n;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(pre[i]<0){
            int x=i;
            cout<<x;
            while(ans[x]){
                cout<<" "<<ans[x];
                x=ans[x];
            }
            cout<<endl;
        }
    }
    cout<<res<<endl;
    // for(int i=1;i<=n;i++) p[i]=i;
    // for(int i=1;i<=n;i++){
    //     if(!st[i]){
    //         for(auto x:plt.g[i]){
    //             if(x>n) x-=n;
    //             cout<<x<<" "
    //         }
    //     }
    // }


    return 0;
}
