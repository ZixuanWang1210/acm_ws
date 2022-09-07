
// P2765 魔术球问题 
// P2764 最小路径覆盖问题
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

int n;
bool check(int x){
    int t=sqrt(x);
    if(t*t==x) return true;
    else return false;
}
const int maxn=1000;
int pre[maxn],ans[maxn];

void sol(){
    cin>>n;
    memset(pre,-1,sizeof pre);

    Flow<int> plt(1000000);

    int S=0,T=1;
    int num=0,res=0,tmp,tot=0;
    while(1){
        tot++,num++;
        plt.addEdge(S,num*2,1);
        plt.addEdge(num*2+1,T,1);
        for(int i=1;i<num;i++){
            if(check(i+num)){
                plt.addEdge(i*2,num*2+1,1);
            }
        }
        tot-=plt.maxFlow(S,T);
        if(tot>n) break;
    }
    cout<<num-1<<endl;
    for(int i=1;i<=num-1;i++){
        int L=i*2,R=i*2+1;
        for(int j=0;j<plt.g[L].size();j++){
            int k=plt.g[L][j];
            int v=plt.e[k].to,f=plt.e[k^1].cap;
            if(v/2&&f>0){
                pre[v/2]=i;
                ans[i]=v/2;
            }
        }
    }
    for(int i=1;i<=num-1;i++){
        if(pre[i]<0){
            int x=i;
            cout<<x;
            while(ans[x]){
                cout<<' '<<ans[x];
                x=ans[x];
            }
            cout<<endl;
        }
    }

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
