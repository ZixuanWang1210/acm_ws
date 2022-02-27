//地杰斯特拉无法求最长路
//分层图
#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int N=100000*3+10, M=100000*2*10;
int h[N],e[M],ne[M],w[M],idx;
int dis[N];
bool st[N];
int n,m;

void add(int a,int b,int c=0){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void spfa(){
    memset(dis,-0x3f,sizeof dis);
    queue<int>q;
    q.push(1);
    st[1]=true;
    dis[1]=0;

    while(q.size()){
        int t=q.front(); q.pop(); st[t]=false;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            if(dis[j]<dis[t]+w[i]){
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
    for(int i=1;i<=n;i++){
        int c; cin>>c;
        add(i,i+n,-c), add(i+n,i+2*n,c);
    }
    for(int i=1;i<=m;i++){
        int x,y,z; cin>>x>>y>>z;
        if(z==1){
            add(x,y), add(x+n,y+n), add(x+2*n,y+2*n);
        }
        else{
            add(x,y), add(x+n,y+n), add(x+2*n,y+2*n);
            add(y,x), add(y+n,x+n), add(y+2*n,x+2*n);
        }
    }

    spfa();

    cout<<dis[3*n]<<endl;

    return 0;
}