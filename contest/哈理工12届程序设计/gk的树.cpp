#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
using namespace std;

const int maxn=5e5+10;
int h[maxn],e[maxn],ne[maxn],idx;
int d[maxn];
int ans,k,n;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    d[a]++;
}

void dfs(int u,int fa){
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,u);
        if(d[j]>k){
            int det=d[j]-k;
            // cout<<d[1]<<' '<<j<<' '<<d[j]<<' '<<det<<endl;
            d[j]-=det;
            d[u]-=1;
            ans+=det;
        }
    }
}

void sol(){
    cin>>n>>k;
    for(int i=0;i<=4*n;i++){
        h[i]=-1;
        e[i]=0;
        ne[i]=0;
        d[i]=0;
    }
    idx=0;
    ans=0;
    for(int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        add(u,v),add(v,u);
    }
    dfs(1,-1);
    if(d[1]>k){
        int det=d[1]-k;
        ans+=det;
    }
    cout<<ans<<endl;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
