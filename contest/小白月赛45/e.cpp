#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long
using namespace std;

const int N=1e5+10;
int n;
int idx;
int p[N],siz[N];

int find(int x){
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

void merge(int x,int y,int z){
    int a=find(x),b=find(y);
    p[a]=b;
    siz[b]=max(siz[b],siz[b]+siz[a]+z);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        p[i]=i;
        cin>>siz[i];
    }
    for(int i=1;i<=n-1;i++){
        int u,v,w; cin>>u>>v>>w;
        if(find(u)!=find(v)){
            merge(u,v,w);
        }
    }
    int ans=-0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        if(p[i]==i) ans=max(ans,siz[i]);
    }
    cout<<ans;
    

    return 0;
}
