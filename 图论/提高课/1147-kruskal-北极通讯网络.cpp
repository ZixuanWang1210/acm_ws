#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int maxn=5e5+10;
int n,k;
double ans;
pii e[maxn];
int fa[maxn];
struct Node{
    int u,v;
    double w;
    bool operator<(const Node &t) const{
        return w<t.w;
    }
} edge[maxn];
int cnt;

double _get(pii a,pii b){
    int dx=a.first-b.first,dy=a.second-b.second;
    return sqrt(dx*dx+dy*dy);
}

int find(int x){
    if(x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>e[i].first>>e[i].second;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            double temp=_get(e[i],e[j]);
            edge[++cnt]={i,j,temp};
        }
    }
    // cout<<cnt<<endl;
    sort(edge+1,edge+1+cnt);
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    // cout<<cnt<<endl;
    int res=n;
    for(int i=1;i<=cnt;i++){

        if(res<=k) break;
        int a=find(edge[i].u),b=find(edge[i].v);
        // cout<<a<<' '<<b<<endl;
        double w=edge[i].w;

        if(a!=b){
            fa[a]=b;
            res--;
            ans=w;
        }
    }
    // cout<<res<<endl;
    cout<<fixed<<setprecision(2)<<ans<<endl;

    return 0;
}