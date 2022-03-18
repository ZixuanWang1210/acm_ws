//带权并查集->经典
#include<bits/stdc++.h>
using namespace std;

int n,m,ans;
const int maxn=2e5+10;
int p[maxn],sum[maxn];

int find(int x){
    if(x!=p[x]){
        int px=find(p[x]);
        sum[x]+=sum[p[x]];
        p[x]=px;
    }
    return p[x];
}

bool merge(int x,int y,int d){
    int px=find(x),py=find(y);
    if(px==py){
        if(sum[x]-sum[y]!=d) return 1;
    }
    else {
        if(px<py){
            p[px]=py;
            sum[px]=sum[y]+d-sum[x];
        }
        else{
            p[py]=px;
            sum[py]=sum[x]-sum[y]-d;
        }
    }
    return 0;
}


int main(){

    cin>>n>>m;
    for(int i=0;i<=n;i++) p[i]=i,sum[i]=0;
    int ans=0;
    for(int i=1;i<=m;i++){
        int x,y,d; cin>>x>>y>>d;
        if(merge(x,y+1,d)) ans++;
    }
    cout<<ans;


    return 0;
}