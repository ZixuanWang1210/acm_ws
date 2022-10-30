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

int n;
const int maxn=1e6+10;
int h[maxn],ne[maxn],e[maxn],idx;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int q;
struct LCA {
    /*
    $st[cnt][0]$：树的 $dfs$ 序，第 $cnt$ 个遍历的点是 $st[cnt][0]$
    $dfn[x]$：节点编号为x的节点，第一次出现在dfs序中的位置
    $dep[x]$：节点x在树中的深度
    */

   // 修改 st 的大小
    int dfn[maxn], dep[maxn], st[maxn][40], cnt;
    void dfs(int x, int fa) {
        dfn[x] = ++cnt, dep[x] = dep[fa] + 1, st[cnt][0] = x;
        for (int i = h[x]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == fa) continue;
            dfs(j, x);
            st[++cnt][0] = x;
        }
    }

    void RMQ() {
        for (int j = 1; j <= 30; j++) {
            for (int i = 1; (i + (1 << j) - 1) <= cnt; i++) {
                int r = i + (1 << (j - 1));
                st[i][j] = dep[st[i][j - 1]] < dep[st[r][j - 1]] ? st[i][j - 1] : st[r][j - 1];
            }
        }
    }

    int get(int l, int r) {
        l = dfn[l], r = dfn[r];
        if (l > r) swap(l, r);
        int k = log2(r - l + 1);
        int res = dep[st[l][k]] < dep[st[r - (1 << k) + 1][k]] ? st[l][k] : st[r - (1 << k) + 1][k];
        return res;
    }
    
    void init(int root) {
        dfs(root, 0);
        RMQ();
    }
} plt;

int get(int x,int y){
    return plt.dep[x]+plt.dep[y]-2*plt.dep[plt.get(x,y)];
}

void sol(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        add(u,v),add(v,u);
    }

    plt.init(1);

    cin>>q;
    while(q--){
        // int cnt; cin>>cnt;
        // vector<int> v;
        // int ans=0,y=0;
        // for(int i=1;i<=cnt;i++){
        //     int x; cin>>x;
        //     if(plt.dep[x]>plt.dep[y]) y=x;
        //     v.push_back(x);
        // }
        // for(auto x:v) ans=max(ans,get(y,x));
        // cout<<(ans+1)/2<<endl;
        vector<int> v;
        int num, x; cin >> num;
        int maxz = 0, u = 0;
        for(int i = 1; i <= num; i++) {
        cin >> x, v.push_back(x);
        //cout << x << ' ' << deg[x] << "\n";
        if(plt.dep[x] > maxz) {
            maxz = plt.dep[x];
            u = x;
        }
        }
        maxz = 0;
        for(auto x : v) {
        maxz = max(maxz, get(u, x));
        }
        cout << (maxz + 1) / 2 << "\n";
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
