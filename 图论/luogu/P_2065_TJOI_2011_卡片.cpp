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
const int maxn=1e7+10;
bool st[maxn];
int pri[maxn],cnt;
map<int,int> mp;
void sol(){
    int n,m; cin>>n>>m;
    vector<int> v1(n+1),v2(m+1);
    set<int> st;
    for(int i=1;i<=n;i++){
        cin>>v1[i];
        int x=v1[i];
        for(int j=2;j<=x/j;j++){
            int cnt=0;
            while(x%j==0){
                cnt++;
                x/=j;
            }
            if(cnt) st.insert(j);
        }
        if(x>1) st.insert(x);
    }
    for(int i=1;i<=m;i++){
        cin>>v2[i];
        int x=v2[i];
        for(int j=2;j<=x/j;j++){
            int cnt=0;
            while(x%j==0){
                cnt++;
                x/=j;
            }
            if(cnt) st.insert(j);
        }
        if(x>1) st.insert(x);
    }
    map<int,int> mp;
    int idx=0;
    for(auto x:st){
        mp[x]=++idx;
    }
    
    Flow<int> plt(n+m+2+idx);
    int S=0,T=n+m+1+idx;

    for(int i=1;i<=n;i++){
        int x=v1[i];
        for(int j=2;j<=x/j;j++){
            int cnt=0;
            while(x%j==0){
                cnt++;
                x/=j;
            }
            if(cnt) plt.addEdge(i,mp[j]+n+m,1);
        }
        if(x>1) plt.addEdge(i,mp[x]+n+m,1);
    }
    for(int i=1;i<=m;i++){
        int x=v2[i];
        for(int j=2;j<=x/j;j++){
            int cnt=0;
            while(x%j==0){
                cnt++;
                x/=j;
            }
            if(cnt) plt.addEdge(mp[j]+n+m,i+n,1);
        }
        if(x>1) plt.addEdge(mp[x]+n+m,i+n,1);
    }

    for(int i=1;i<=n;i++) plt.addEdge(S,i,1);
    for(int i=1;i<=m;i++) plt.addEdge(i+n,T,1);

    cout<<plt.maxFlow(S,T)<<endl;

}


signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
