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

int n,m;
const int maxn=3e4+10;
int h[maxn*10],ne[maxn*10],e[maxn*10],idx;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int din[maxn];
bitset<maxn> d[maxn],w[maxn];
void sol(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        din[v]++;
        add(u,v);
        w[v][u]=1;
    }

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(din[i]==0){
            q.push(i);
        }
    }
    int ans=0;
    while(q.size()){
        int t=q.front(); q.pop();
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            din[j]--;
            d[j]|=d[t]|w[t];
            if(!din[j]) q.push(j);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=h[i];~j;j=ne[j]){
            int v=e[j];
            ans+=d[v][i];
        }
    }

    cout<<ans<<endl;
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
