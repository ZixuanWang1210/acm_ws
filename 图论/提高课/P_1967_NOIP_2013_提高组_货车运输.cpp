#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int maxn=5e6+10;
int n,m;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
int dis[maxn];
bool st[maxn];
pii ask[maxn],cnt;

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void spfa(){
    memset(dis,-0x3f,sizeof dis);
    dis[0]=530554783;
    // cout<<dis[0]<<endl;

    queue<int> q;
    q.push(0);
    st[0]=true;
    while(q.size()){
        int t=q.front(); q.pop(); st[t]=false;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            // if(t==0){
            //     st[j]=true;
            //     q.push(j);
            // }
            if(dis[j]<min(dis[t],w[i])){
                dis[j]=min(dis[t],w[i]);
                // cout<<j<<' '<<dis[j]<<endl;
                if(!st[j]){
                    st[j]=true;
                    q.push(j);
                }
            }
        }
    }
}

int main(){ 
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int x,y,z; cin>>x>>y>>z;
        add(x,y,z),add(y,x,z);
    }
    int q; cin>>q;
    for(int i=1;i<=q;i++){
        cin>>ask[i].first>>ask[i].second;
        add(0,ask[i].first,530554783),add(ask[i].first,0,530554783);
    }
    spfa();
    for(int i=1;i<=q;i++){
        if(dis[ask[i].second]<0) cout<<-1<<endl;
        else cout<<dis[ask[i].second]<<endl;
    }

    return 0;
}