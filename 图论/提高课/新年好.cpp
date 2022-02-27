#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int maxn=5e5+10;

int h[maxn],ne[maxn],w[maxn],e[maxn],idx;
int n,m;
int dis[maxn],g[6][6];
bool st[maxn];
int source[6];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void dij(int indx){
    memset(st,0,sizeof st);
    memset(dis,0x3f,sizeof dis);

    int start=source[indx];
    dis[start]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,start});

    while(pq.size()){
        auto t=pq.top(); pq.pop();
        int ver=t.second, dist=t.first;
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

    for(int i=0;i<6;i++) g[indx][i]=dis[source[i]];
    // for(int i=0;i<6;i++) cout<<dis[source[i]]<<endl;
    // cout<<endl;
}

int dfs(int u,int indx,int dist){
    if(u==5) return dist;

    int res=0x3f3f3f3f;
    for(int i=1;i<=5;i++){
        if(!st[i]){
            st[i]=true;
            res=min(res,dfs(u+1,i,dist+g[indx][i]));
            st[i]=false;
        }
    }
    return res;
}

int main(){
    cin>>n>>m;
    source[0]=1;
    for(int i=1;i<=5;i++){
        cin>>source[i];
    }

    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int x,y,t; cin>>x>>y>>t;
        add(x,y,t),add(y,x,t);
    }

    for(int i=0;i<=5;i++){
        dij(i);
    }

    memset(st,0,sizeof st);
    cout<<dfs(0,0,0)<<endl;

    return 0;
}