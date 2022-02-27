#include<bits/stdc++.h>
using namespace std;

const int N=100+10,M=110*110+10;
int h[N],e[M],ne[M],w[M],idx;
int m,n;
struct obj{
    int id,p,l,x;
} obj[M];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int main(){
    cin>>m>>n;
    int maxl=-1;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        int p,l,x; cin>>p>>l>>x;
        obj[i]={i,p,l,x};
        maxl=max(maxl,l);
        add(0,i,p);
        for(int j=1;j<=x;j++){
            int t,v; cin>>t>>v;
            add(t,i,v);
        }
    }

    for(int i=obj[1].l-k;i<=obj[1].l;i++){
        spfa(i,i+k);
        ans=min()
    }

    return 0;
}