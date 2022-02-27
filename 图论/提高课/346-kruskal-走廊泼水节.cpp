#include<bits/stdc++.h>
using namespace std;

const int maxn=6000*6000+10;
struct node{
    int u,v,w;
    bool operator<(const node&t) const{
        return w<t.w;
    }
} edge[maxn];
int idx;
int n,t;
int p[maxn],size[maxn];

int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

void sol(){
    int ans=0;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
    }

    sort(edge+1,edge+n);

    for(int i=1;i<=n;i++) p[i]=i,size[i]=1;

    for(int i=1;i<n;i++){
        int u=edge[i].u,v=edge[i].v,w=edge[i].w;
        int a=find(u),b=find(v);
        if(a!=b){
            ans+=(size[a]*size[b]-1)*(w+1);
            size[a]+=size[b];
            p[b]=a;
        }
    }
    cout<<ans<<endl;
}

int main(){
    cin>>t;
    while(t--){
        sol();
    }


    return 0;
}