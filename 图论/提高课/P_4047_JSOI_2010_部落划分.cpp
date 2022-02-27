//最小生成树
#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

const int maxn=1e6+10;
struct node{
    int u,v;
    double w;
    bool operator<(const node&t) const{
        return w<t.w;
    }
} edge[maxn];
int n,k,idx;
pii e[maxn];
int p[maxn];

int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

double _get(pii a,pii b){
    int dx=a.first-b.first;
    int dy=a.second-b.second;
    return sqrt(dx*dx+dy*dy);
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>e[i].first>>e[i].second;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            edge[++idx]={i,j,_get(e[i],e[j])};
        }
    }
    sort(edge+1,edge+1+idx);

    for(int i=1;i<=n;i++) p[i]=i;

    int cnt=0;
    bool flag=false;
    for(int i=1;i<=idx;i++){
        int u=edge[i].u,v=edge[i].v;
        double w=edge[i].w;

        int a=find(u),b=find(v);
        if(a!=b){
            p[a]=b;
            cnt++;
            if(cnt==n-k+1){
                cout<<fixed<<setprecision(2)<<w<<endl;
                return 0;
            }
        }
    }

    return 0;
}
