#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn=3e6+10;
int h[maxn],ne[maxn],e[maxn],idx;
int size[maxn],ans[maxn];
int n;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int fa){
    size[u]=1;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,u);
        size[u]+=size[j];
    }
}

void dfs2(int u,int fa){
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        ans[j]=ans[u]-2*size[j]+n;
        dfs2(j,u);
    }
}

signed main(){
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        add(u,v),add(v,u);
    }

    dfs(1,-1);
    
    for(int i=1;i<=n;i++){
        ans[1]+=size[i];
    }
    dfs2(1,-1);
    int res=0,id=0;
    for(int i=1;i<=n;i++){
        if(ans[i]>res) res=ans[i],id=i;
    }

    cout<<id<<endl;
    return 0;
}