// #include <bits/stdc++.h>
// #define endl "\n"
// #define debug(x) cout << #x << ": -----> " << x << endl;
// #define inf 0x3f3f3f3f
// #define pii pair<int,int>
// #define all(x) x.begin()+1,x.end()
// #define _all(x) x.begin(),x.end()
// #define mod 1000000007
// #define ll long long
// // #define int long long

// using namespace std;
// template<class T>
// struct Flow {
//     const int n;
//     struct Edge {
//         int to;
//         T cap;
//         Edge(int to, T cap) : to(to), cap(cap) {}
//     };
//     std::vector<Edge> e;
//     std::vector<std::vector<int>> g;
//     std::vector<int> cur, h;
//     Flow(int n) : n(n), g(n) {}
    
//     bool bfs(int s, int t) {
//         h.assign(n, -1);
//         std::queue<int> que;
//         h[s] = 0;
//         que.push(s);
//         while (!que.empty()) {
//             const int u = que.front();
//             que.pop();
//             for (int i : g[u]) {
//                 auto [v, c] = e[i];
//                 if (c > 0 && h[v] == -1) {
//                     h[v] = h[u] + 1;
//                     if (v == t) {
//                         return true;
//                     }
//                     que.push(v);
//                 }
//             }
//         }
//         return false;
//     }
    
//     T dfs(int u, int t, T f) {
//         if (u == t) {
//             return f;
//         }
//         auto r = f;
//         for (int &i = cur[u]; i < int(g[u].size()); ++i) {
//             const int j = g[u][i];
//             auto [v, c] = e[j];
//             if (c > 0 && h[v] == h[u] + 1) {
//                 auto a = dfs(v, t, std::min(r, c));
//                 e[j].cap -= a;
//                 e[j ^ 1].cap += a;
//                 r -= a;
//                 if (r == 0) {
//                     return f;
//                 }
//             }
//         }
//         return f - r    ;
//     }
//     void addEdge(int u, int v, T c) {
//         g[u].push_back(e.size());
//         e.emplace_back(v, c);
//         g[v].push_back(e.size());
//         e.emplace_back(u, 0);
//     }
//     T maxFlow(int s, int t) {
//         T ans = 0;
//         while (bfs(s, t)) {
//             cur.assign(n, 0);
//             ans += dfs(s, t, std::numeric_limits<T>::max());
//         }
//         return ans;
//     }
// };

// const int maxn=5e5+10;
// struct node{
//     int u,v,w;
// };
// int n,m,t,S,T;
// vector<node> vec;
// vector<node> seg;

// void sol(){
//     // Flow<int> plt(5000)
//     cin>>n>>m>>t;
//     S=1,T=n;
//     for(int i=1;i<=m;i++){
//         int u,v,w; cin>>u>>v>>w;
//         vec.push_back({u,v,w});
//         // plt.addEdge(u,v,w);
//         seg.push_back({u,v,w});
//     }
//     int res=1;
//     int mf;
//     int re=-1;

//     Flow<int> plt1(50000);
//     for(auto x:seg){
//         int u=x.u,v=x.v,w=x.w;
//         plt1.addEdge(u,v,w);
//     }
//     if(plt1.maxFlow(1,n)>=t){
//         cout<<1<<endl;
//         return;
//     }
//     while(1){
//         // cout<<plt.maxFlow(S,T)<<endl;
//         // cout<<"case #1 :"<<endl;
//         Flow<int> plt(50000);
//         for(auto x:seg){
//             int u=x.u,v=x.v,w=x.w;
//             // cout<<"add: "<<u<<' '<<v<<" "<<w<<endl;
//             plt.addEdge(u,v,w);
//             // seg.push_back({u,v,w});
//         }
//         for(auto x:vec){
//             int u=x.u,v=x.v,w=x.w;
//             plt.addEdge(u+n*res,v+n*res,w);
//             seg.push_back({u+n*res,v+n*res,w});
//             // cout<<"add: "<<u+n*res<<' '<<v+n*res<<" "<<w<<endl;
//         }
//         for(int i=1;i<=n;i++){
//             plt.addEdge(i+n*(res-1),i+n*res,inf);
//             seg.push_back({i+n*(res-1),i+n*res,inf});
//             // cout<<"add: "<<i+n*(res-1)<<' '<<i+n*res<<" "<<inf<<endl;
//         }
//         res++;
//         S=1,T=res*n;
//         // cout<<S<<" "<<T<<endl;
//         mf=plt.maxFlow(S,T);
//         // cout<<mf<<' '<<t<<endl;
//         cout<<mf<<' '<<res<<endl;
//         if(mf>=t) {
//             cout<<res+1<<endl;
//             return;
//         }
//         if(mf==re){
//             // cout<<-1<<endl;
//             assert(1==0);
//             return;
//         }
//         re=mf;
//         // if(res==3) return;
//     //     cout<<S<<' '<<T<<endl;
//     // cout<<plt.maxFlow(S,T)<<endl;
//     }
//     // cout<<res<<endl;

// }

// signed main(){
//     ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

//     int _=1;
//     // cin>>_;
//     while(_--){
//         sol();
//     }

//     return 0;
// }
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int V = 500000;
const int E = 500000;

template<typename T>
struct FlowGraph{
    int s, t, vtot;
    int head[V], etot;
    int dis[V], cur[V];
    T flow = 0;
    struct edge {
        int v, nxt;
        T f;
    } e[E * 2];
    void addedge(int u, int v, T f, T f2 = 0){
        e[etot]= {v, head[u], f}; head[u] = etot ++;
        e[etot]= {u, head[v], f2}; head[v] = etot ++;
    }

    bool bfs(){
        for(int i = 1; i <= vtot; i ++){
            dis[i] = 0;
            cur[i] = head[i];
        }
        queue<int> q;
        q.push(s); dis[s] = 1;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = head[u]; ~i; i = e[i].nxt){
                if(e[i].f && !dis[e[i].v]){
                    int v = e[i].v;
                    dis[v] = dis[u] + 1;
                    if(v == t) return true;
                    q.push(v);
                }
            }
        }
        return false;
    }
    T dfs(int u, T m){
        if(u == t) return m;
        T flow = 0;
        for(int i = cur[u]; ~i; cur[u] = i = e[i].nxt){
            if(e[i].f && dis[e[i].v] == dis[u] + 1){
                T f = dfs(e[i].v, min(m, e[i].f));
                e[i].f -= f;
                e[i ^ 1].f += f;
                m -= f;
                flow += f;
                if(!m) break;
            }
        }
        if(!flow) dis[u] = -1;
        return flow;
    }
    T dinic(){
        while(bfs()) flow += dfs(s, numeric_limits<T>::max());
        return flow;
    }
    void init(int s_, int t_, int vtot_){
        s = s_, t = t_, vtot = vtot_;
        etot = 0;
        for(int i = 1; i <= vtot; i ++) head[i] = -1;
    }
};

FlowGraph< int > g;

int n, m, t;
vector< array<int, 2> > e[V];
int main(){
    scanf("%d %d %d", &n, &m, &t);
    int S = 19999, T = 20000;
    g.init(S, T, T);
    for(int i = 1; i <= m; i ++){
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        e[u].push_back({v, w});
    }
    int cnt = 0; g.addedge(n, T, t); g.addedge(S, 1, t);
    while(true){
        cnt ++;
        for(int u = 1; u <= n; u ++){
            for(auto [v, w] : e[u]) g.addedge((cnt - 1) * n + u, cnt * n + v, w);
        }
        g.addedge(cnt * n + n, T, t); g.addedge(S, cnt * n + 1, t);
        int tt = g.dinic();
        cout<<cnt<<' '<<tt<<endl;
        if(tt >= t) break;
    }
    cout << cnt << endl;
}