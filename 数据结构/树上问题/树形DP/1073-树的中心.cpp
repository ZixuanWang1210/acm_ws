#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
int h[maxn],e[maxn],ne[maxn],w[maxn],idx;
int n;
int d1[maxn],d2[maxn],p1[maxn],p2[maxn],up[maxn];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int dfs1(int u,int fa){
    d1[u]=d2[u]=-0x3f3f3f3f;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        int dist=dfs1(j,u)+w[i];
        if(dist>d1[u]){
            d2[u]=d1[u],d1[u]=dist;
            p2[u]=p1[u],p1[u]=j;
        }
        else if(dist>d2[u]){
            d2[u]=dist,p2[u]=j;
        }
    }
    if(d1[u]==-0x3f3f3f3f) d1[u]=d2[u]=0;
    return d1[u];
}

void dfs2(int u,int fa){
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        if(p1[u]==j) up[j]=max(up[u],d2[u])+w[i];
        else up[j]=max(up[u],d1[u])+w[i];
        dfs2(j,u);
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n-1;i++){
        int a,b,c; cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }

    dfs1(1,-1);
    dfs2(1,-1);
    int res=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        res=min(res,max(d1[i],up[i]));
    }
    cout<<res;

    return 0;
}