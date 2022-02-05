#include<bits/stdc++.h>
using namespace std;

const int N=500;
int n,m;
int e[N],ne[N],h[N],idx;
int dis[N],w[N];
bool st[N];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx ++;
}

void spfa(){
    memset(dis,0x3f,sizeof dis);
    dis[1]=0;
    st[1]=true;
    queue<int>q;
    q.push(1);
    while(q.size()){
        int t=q.front();q.pop();st[t]=false;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(dis[j]>dis[t]+w[i]){
                dis[j]=dis[t]+w[i];
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
    for(int i=0;i<m;i++){
        int o,j,k;cin>>o>>j>>k;
        add(o,j,k),add(j,o,k);
    }
    
    spfa();
        
    int res=0;
    for(int i=1;i<=n;i++){
        if(dis[i]>res)
            res=dis[i];
    }
    if(res==0x3f3f3f3f) cout<<-1<<endl;
    else cout<<res<<endl;

    return 0;
}
