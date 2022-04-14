#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long
using namespace std;
const int maxn=3e5+10;

struct DSU {
    std::vector<int> p, siz;
    DSU(int n) : p(n+1), siz(n+1, 1) { std::iota(p.begin(), p.end(), 0); }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        siz[x] += siz[y];
        p[y] = x;
        return true;
    }
    int size(int x) { return siz[find(x)]; }
};

// struct DSU {
//     vector<int> p;
//     vector<int> siz;
//     int n;
//     int comp_cnt;//联通分量个数

//     DSU(int _n): n(_n), comp_cnt(_n), p(_n), siz(_n, 1) {
//         //iota函数的作用是把fa置为[0..n-1]
//         iota(p.begin(), p.end(), 0);
//     }

// 	//查看x是属于哪一个联通分量的
//     int findset(int x) {
//         return p[x] == x ? x : p[x] = findset(p[x]);
//     }

//     void merge(int x, int y) {
//         x = findset(x);
//         y = findset(y);
//         if (x != y) {
//             if (siz[x] < siz[y]) {
//                 swap(x, y);
//             }
//             p[y] = x;
//             siz[x] += siz[y];
//             --comp_cnt;
//         }
//     }
    
// 	//是否是联通的
//     bool same(int x, int y) {
//         x = findset(x);
//         y = findset(y);
//         return x == y;
//     }
// };

int n,m;

struct node{
    int u,v,w;
} seg[maxn];
bool st[maxn];
// int p[maxn];

// int find(int x){
//     if(x!=p[x]) p[x]=find(p[x]);
//     return p[x];
// }

bool check(int k){
    DSU plt(n);
    // for(int i=1;i<=n;i++) p[i]=i;

    for(int i=1;i<=m;i++){
        if(st[i]||seg[i].w&(1ll<<k)) continue;

        int a=seg[i].u,b=seg[i].v;
        plt.merge(a,b);
        // int aa=find(a),bb=find(b);
        // if(aa!=bb) p[aa]=bb;
    }  

    for(int i=1;i<=n;i++){
        if(!plt.same(1,i)) return false;
        // if(find(1)!=find(i)) return false;
    }
    return true;
}

void sol(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w; cin>>u>>v>>w;
        seg[i]={u,v,w};
    }

    for(int i=1;i<=m;i++){
        st[i]=false;
    }
    int res=0;
    for(int i=30;i>=0;i--){
        if(check(i)){
            for(int j=1;j<=m;j++){
                if(seg[j].w&(1<<i)) st[j]=true;
            }
        }
        else res+=(1ll<<i);
    }
    cout<<res<<endl;
}

signed main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }
    

    return 0;
}
