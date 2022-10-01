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

const int maxn=40;
bool mp[maxn][maxn]={0};
int h[maxn][maxn];
int n,m,d;
int cnt;

void sol(){
    cin>>n>>m>>d;
    Flow<int> plt(n*m*2+200);
    int S=0,T=2*n*m+1;
    auto get=[&](int x,int y){
        return (x-1)*m+y;
    };
    auto getd=[&](pii a,pii b){
        double dx=a.first-b.first;
        double dy=a.second-b.second;
        return sqrt(dx*dx+dy*dy);
    };
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c; cin>>c;
            int hh=c-'0';
            if(hh){
                h[i][j]=1;
                plt.addEdge(get(i,j),get(i,j)+n*m,hh);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char x; cin>>x;
            if(x=='L'){
                cnt++;
                mp[i][j]=true;
                plt.addEdge(S,get(i,j),1);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int ii=1;ii<=n;ii++){
                for(int jj=1;jj<=m;jj++){
                    if(i==ii&&j==jj) continue;
                    if(h[i][j]&&h[ii][jj]&&getd(make_pair(i,j),make_pair(ii,jj))<=d){
                        plt.addEdge(m*n+get(i,j),get(ii,jj),inf);
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i>d&&i<=n-d&&j>d&&j<=m-d) continue;
            if(h[i][j]){
                plt.addEdge(get(i,j)+m*n,T,inf);
            }
        }
    }
    cout<<cnt-plt.maxFlow(S,T)<<endl;
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
