#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int N=1e4+10;
int n,m,ans;
int p[N];
struct node{
    int u,v,w;
    bool operator<(node &t) const{
        return w<t.w;
    }
} edge[N];
int idx;

int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

void merge(int a,int b){
    p[find(a)]=find(b);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i;
    while(m--){
        int op,u,v,w;cin>>op>>u>>v>>w;
        if(op==1){
            ans+=w;
            p[find(u)]=find(v);
        }
        else{
            edge[++idx]={u,v,w};
        }
    }
    sort(edge+1,edge+1+idx);

    for(int i=1;i<=idx;i++){
        int a=find(edge[i].u),b=find(edge[i].v),w=edge[i].w;
        if(a!=b){
            p[a]=b;
            ans+=w;
        }
    }

    cout<<ans;
    

    return 0;
}
