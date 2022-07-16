#include<bits/stdc++.h>

using namespace std;

const int N=1300;
const int M=4000;
const int INF=1e9;

int n,m,k,S,T,idx;
int h[N],e[M],ne[M],f[M];
int cur[N],q[N],dist[N],p[N];

struct Ship{
    int id,c,cnt;
    int path[30];
}ship[30];

int find(int u){
    if(u!=p[u]) p[u]=find(p[u]);
    return p[u];
}

//因为包括地球和月球,所以总共n+2个点
int get(int i,int day){
    return day*(n+2)+i;
}

template <class Cap> struct mf_graph {
  public:
    mf_graph() : _n(0) {}
    explicit mf_graph(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap});
        g[to].push_back(_edge{from, from_id, 0});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result;
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }

    Cap flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);

        std::vector<int> level(_n), iter(_n);


        auto bfs = [&]() {
            std::fill(level.begin(), level.end(), -1);
            level[s] = 0;
            std::queue<int> que;
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d =
                    self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) return res;
            }
            level[v] = _n;
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            std::fill(iter.begin(), iter.end(), 0);
            Cap f = dfs(dfs, t, flow_limit - flow);
            if (!f) break;
            flow += f;
        }
        return flow;
    }

    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(_n);
        std::queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }

  private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

//0表示地球,n+1表示月球
int main(){
    cin>>n>>m>>k;
    mf_graph<int> plt(N+1);
    S=N-2,T=N-1;

    for(int i=0;i<=n+1;++i) p[i]=i;

    for(int i=0;i<m;++i){
        int c,cnt;
        cin>>c>>cnt;
        ship[i].id=i;
        ship[i].cnt=cnt;
        ship[i].c=c;
        for(int j=0;j<cnt;++j){
            int pos;
            cin>>pos;
            if(pos==-1) pos=n+1;
            ship[i].path[j]=pos;
            if(j){
                int a=ship[i].path[j-1];
                int b=ship[i].path[j];
                a=find(a);
                b=find(b);
                p[a]=b;
            }
        }
    }
    //不联通说明无解
    if(find(0)!=find(n+1)) puts("0");
    else{
        plt.add_edge(S,get(0,0),INF);
        plt.add_edge(get(n+1,0),T,INF);
        int day=1;
        int res=0;
        while(1){
            //新的一天
            //月球向T连一条正无穷的边
            plt.add_edge(get(n+1,day),T,INF);
            //每个点前一天向当天连一条正无穷的边
            for(int i=0;i<=n+1;++i) plt.add_edge(get(i,day-1),get(i,day),INF);
            //每辆车前一天的位置向当天的位置连一条容量等于车的容量的边
            for(int i=0;i<m;++i){
                int cnt=ship[i].cnt;
                int a=ship[i].path[(day-1)%cnt];
                int b=ship[i].path[day%cnt];
                int c=ship[i].c;
                plt.add_edge(get(a,day-1),get(b,day),c);
            }

            res+=plt.flow(S,T);
            if(res>=k) break;//所有人都接到了
            day++;
        }
        printf("%d\n",day);
    }

    return 0;
}
