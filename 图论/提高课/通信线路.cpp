#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int N=1000000+10,M=10000000+10; //容易爆空间
int e[M],ne[M],h[N],w[M],idx;
bool st[N];
int dis[N];
int n,p,k;


void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void dij(){
    memset(dis,0x3f,sizeof dis);
    dis[1]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,1});

    while(pq.size()){
        auto t=pq.top(); pq.pop();
        int ver=t.second, d=t.first;
        if(st[ver]) continue;
        st[ver]=true;
        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            int z=max(w[i],dis[ver]);
            if(dis[j]>z){
                dis[j]=z;
                pq.push({dis[j],j});
            }
        }
    }

}

int main(){
    cin>>n>>p>>k;
    memset(h,-1,sizeof h);
    for(int i=1;i<=p;i++){
        int a,b,l; cin>>a>>b>>l;
        add(a,b,l), add(b,a,l);
        for(int j=1;j<=k;j++){
            add(a+(j-1)*n,b+j*n,0), add(b+(j-1)*n,a+j*n,0);//上层到下层的双向边
            add(a+j*n,b+j*n,l), add(b+j*n,a+j*n,l);//下层的双向边
        }
    }
    for(int i=1;i<=k;i++){
        add(i*n,(i+1)*n,0);
    }

    dij();

    if(dis[(k+1)*n]==1061109567) puts("-1");
    else cout<<dis[(k+1)*n]<<endl;

    return 0;
}
