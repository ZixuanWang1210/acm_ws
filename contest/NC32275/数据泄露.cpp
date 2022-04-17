#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
#define int long long
// typedef unsigned long long ull;
#define pii pair<int,int>
using namespace std;

const int maxn=1e6+10;
int h[maxn],ne[maxn],w[maxn],e[maxn],idx;
int n,m,k;


void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

bool st[maxn];
int dis[maxn];
int dij(int bg,int ed){
    memset(st,0,sizeof st);
    memset(dis,0x7f7f7f7f,sizeof dis);
    // cout<<1<<endl;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dis[bg]=0;
    pq.push({0,bg});

    while(pq.size()){
        int ver=pq.top().second,dist=pq.top().first;
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
    if(dis[ed]>0x7f7f7f7f/2) return -1;
    else return dis[ed];
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int a,b,s; cin>>a>>b>>s;
        add(a,b,s),add(b,a,s);
    }
    cin>>k;
    vector<int> v;
    v.push_back(1);
    for(int i=1;i<=k;i++){
        int t; cin>>t;
        v.push_back(t);
    }
    int ans=0;
    for(int i=0;i<v.size()-1;i++){
        int res=dij(v[i],v[i+1]);
        if(res==-1){
            cout<<-1<<endl;
            return 0;
        }
        else ans+=res;
    }
    cout<<ans<<endl;

    return 0;
}
