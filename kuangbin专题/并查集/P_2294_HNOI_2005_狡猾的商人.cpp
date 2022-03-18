#include<bits/stdc++.h> 
using namespace std;

int w,n,m;
const int maxn=1000;
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
    else{
        if(px<py){
            p[px]=py;
            sum[px]=sum[y]+d-sum[x];
        }
        else{
            p[py]=px;
            sum[py]=sum[x]-d-sum[y];
        }
    }
    return 0;
}

int main(){
    cin>>w;
    while(w--){
        int n,m; cin>>n>>m;
        for(int i=0;i<=n;i++){
            p[i]=i,sum[i]=0;
        }
        
        bool bz=true;
        while(m--){
            int s,t,v; cin>>s>>t>>v;
            s--;
            if(merge(s,t,v)) bz=false;
        }
        if(bz) cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }

    return 0;
}