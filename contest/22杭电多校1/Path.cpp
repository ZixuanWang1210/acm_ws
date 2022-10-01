// https://zhuanlan.zhihu.com/p/543629481
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

const int maxn=3e6+10;
int n,m,k;
int h[maxn],ne[maxn],w[maxn],e[maxn],idx,w1[maxn];
int dis[maxn][3];
bool st[maxn];
int S;

void add(int a,int b,int c,int op){
    e[idx]=b,w[idx]=c,w1[maxn]=op,ne[idx]=h[a],h[a]=idx++;
}

void sol(){
    cin>>n>>m>>S>>k;
    set<int> sp;
    while(m--){
        int u,v,w,p; cin>>u>>v>>w>>p;
        add(u,v,w,p),add(u+n,v+n,w,p);
        if(p) sp.insert(u),sp.insert(v);
    }
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
