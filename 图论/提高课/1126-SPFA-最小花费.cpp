#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,m;
int e[N],ne[N],h[N],idx;
double dis[N],w[N];
bool st[N];
int a,b;

void add(int a,int b,double c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx ++;
}

void spfa(){
    // for(int i=1;i<=n;i++) dis[i]=1;
    memset(dis,0x3f,sizeof dis);
    dis[a]=1;
    st[a]=true;
    queue<int>q;
    q.push(a);
    while(q.size()){
        int t=q.front();q.pop();st[t]=false;
        for(int i=h[t];~i;i=ne[i]){
            int j=e[i];
            // cout<<dis[j]<<endl;
            if(dis[j]<dis[t]*w[i]){
                // cout<<-1<<endl;
                dis[j]=dis[t]*w[i];
                // cout<<dis[j]<<endl;
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
        int o,j;
        double k;
        cin>>o>>j>>k;
        k=1-k/100;
        // cout<<k<<endl;
        add(o,j,k),add(j,o,k);
    }
    cin>>a>>b;
    spfa();
        
    cout<<fixed<<setprecision(8)<<100/dis[b];

    return 0;
}
