#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+10;
int e[maxn],ne[maxn],w[maxn],h[maxn],idx;
int n,m;
int color[maxn];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

bool dfs(int u,int c,int mid){
    color[u]=c;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(w[i]<=mid) continue;
        if(color[j]){
            if(color[j]==c) return false;
        }
        else if(!dfs(j,3-c,mid)) return false;
    }
    return true;
}

bool check(int x){
    memset(color,0,sizeof color);
    for(int i=1;i<=n;i++){
        if(!color[i]){
            if(!dfs(i,1,x)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int a,b,c; cin>>a>>b>>c;
        add(a,b,c),add(b,a,c);
    }

    int l=0,r=1e5,ans=0;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans<<endl;

    return 0;
}