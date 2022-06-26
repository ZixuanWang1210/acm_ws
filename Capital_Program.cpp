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

const int maxn=5e5+10;
int h[maxn],ne[maxn],e[maxn],idx;
int d[maxn];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    d[a]++;
}

int n,k;

void sol(){
    cin>>n>>k;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        add(u,v),add(v,u);
    }
    int cnt=0;
    queue<pii> q;
    for(int i=1;i<=n;i++){
        // cout<<d[i]<<' ';
        if(d[i]==1){
            q.push({i,1});
        }
    }
    while(q.size()){
        // cout<<q.front().first<<endl;
        auto t=q.front();
        cnt++;
        if(cnt==n-k){
            cout<<t.second<<endl;
            return;
        }
        q.pop();

        for(int i=h[t.first];~i;i=ne[i]){
            int j=e[i];
            d[j]--;
            if(d[j]==1) q.push({j,t.second+1});
        }
    }  
    cout<<-1<<endl;
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
