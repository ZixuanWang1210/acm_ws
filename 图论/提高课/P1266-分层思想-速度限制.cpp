#include<bits/stdc++.h>
#define pii pair<double,pair<int,int>>
using namespace std;

const int maxn=200005;
int n,m,d;
double dis[205][1005];
bool st[205][1005];
pair<int,int> from[205][1005];
int h[maxn],e[maxn],ne[maxn],w[maxn],v[maxn],idx;

void add(int a,int b,int c,int d){
    e[idx]=b,w[idx]=c,v[idx]=d,ne[idx]=h[a],h[a]=idx++;
}

void dij(){
    memset(dis,0x43,sizeof dis);
    memset(st,0,sizeof st);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    dis[0][70]=0;
    pq.push({0,{0,70}});//time,idx,speed

    while(pq.size()){
        int ver=pq.top().second.first,vel=pq.top().second.second;
        double dist=pq.top().first;
        pq.pop();
        if(st[ver][vel]) continue;
        st[ver][vel]=true;

        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            int speed=v[i]?v[i]:vel;
            double time=(double)w[i]/(double)speed;
            if(dis[j][speed]>dis[ver][vel]+time){

                dis[j][speed]=dis[ver][vel]+time;
                from[j][speed]={ver,vel};
                pq.push({dis[j][speed],{j,speed}});

            }

        }
    }
}

void write(int x,int y){
    if(x==0){
        cout<<"0 ";
        return;
    }
    write(from[x][y].first,from[x][y].second);
    cout<<x<<' ';
    return;
}

int main(){
    cin>>n>>m>>d;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int a,b,v1,l; cin>>a>>b>>v1>>l;
        add(a,b,l,v1);
    }

    dij();

    int maxx=0;
    dis[d][maxx]=1e9;
    for(int i=0;i<=500;i++){
        if(dis[d][i]<dis[d][maxx]) maxx=i;
    }
    // cout<<maxx<<endl;
    write(d,maxx);



    return 0;
}