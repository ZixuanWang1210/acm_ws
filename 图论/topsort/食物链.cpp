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
const int maxn=5e5+10;
int h[maxn],ne[maxn],e[maxn],idx;
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int dp[maxn];
int din[maxn],dout[maxn];
int b[maxn];
void sol(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        add(u,v);
        din[v]++;dout[u]++;
    }

    queue<int> q;
    vector<int> top;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(din[i]==0) q.push(i),dp[i]=1;
        else if(!dout[i]) b[i]=1;
    }
    while(q.size()){
        int t=q.front(); q.pop();
        if(b[t]) ans+=dp[t];
        top.push_back(t);
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            dp[j]+=dp[t];
            din[j]--;
            if(!din[j]) q.push(j);
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
