#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define pii pair<int,int>
using namespace std;

int n,m;
const int maxn=5e5+10;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
bool st[maxn];
int dis[maxn];
int S,T;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void dij(){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,S});
    memset(dis,0x3f,sizeof dis);
    memset(st,0,sizeof st);
    dis[S]=0;
    
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

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    cin>>S>>T;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int x,y,z; cin>>x>>y>>z;
        add(x,y,z),add(y,x,z);
    }

    dij();
    if(dis[T]!=0x3f3f3f3f){
        cout<<dis[T]<<endl;
    }
    else cout<<-1<<endl;

    return 0;
}
