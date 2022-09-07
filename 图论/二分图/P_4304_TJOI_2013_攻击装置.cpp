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


const int maxn=4000;
int dx[8]={1,1,-1,-1,2,2,-2,-2},dy[8]={2,-2,2,-2,1,-1,1,-1};
// int dx[4]={1,2,2,1},dy[4]={2,1,-1,-2};
int mp[maxn][maxn];
int n;

int get(int x,int y){
    return (x-1)*n+y;
}
int cnt=0;
void sol(){
    cin>>n;
    Flow<int> plt(10000);
    for(int i=1;i<=n;i++){ 
        for(int j=1;j<=n;j++){
            char t; cin>>t;
            mp[i][j]=t-'0';
            if(mp[i][j]) cnt++;
        }
    }

    int S=0,T=9999;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mp[i][j]) continue;
            if((i+j)&1){
                plt.addEdge(get(i,j),T,1);
                continue;
            }
            plt.addEdge(S,get(i,j),1);
            for(int k=0;k<8;k++){
                int x=i+dx[k],y=j+dy[k];
                if(x<1||x>n||y<1||y>n||mp[x][y]==1) continue;
                plt.addEdge(get(i,j),get(x,y),1);
            }
            // if(mp[i][j]==0){
            //     plt.addEdge(S,get(i,j),1);
            //     plt.addEdge(get(i,j)+n*n,T,1);
            //     }
        }
    }
    cout<<n*n-cnt-plt.maxFlow(S,T)<<endl;


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
