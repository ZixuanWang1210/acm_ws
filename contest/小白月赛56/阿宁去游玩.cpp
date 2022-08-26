#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

const int maxn=5e6+10;
int n,m;
int x,y,z; 
int tt[maxn];

int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
bool st[maxn];
int dis[maxn];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void dij(){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,1});
    memset(dis,0x3f,sizeof dis);
    memset(st,0,sizeof st);
    dis[1]=0;
    
    while(pq.size()){
        int dist=pq.top().first,ver=pq.top().second;
        pq.pop();
        if(st[ver]) continue;
        st[ver]=true;

        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            if(dis[j]>dist+w[i]){
                dis[j]=dist+w[i];
                pq.push({dis[j],j});
            }
        }
    }
}

void sol(){
    cin>>n>>m;
    cin>>x>>y>>z;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++) cin>>tt[i];

    for(int i=1;i<=m;i++){
        int a,b,c; cin>>a>>b;
        if(tt[a]==tt[b]) add(a,b,min(x,z+x)),add(b,a,min(x,z+x));
        else add(a,b,min(y,y+z)),add(b,a,min(y,y+z));
    }

    dij();
    cout<<dis[n]<<endl;
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
