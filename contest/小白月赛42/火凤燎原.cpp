#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=1e6+10;
int h[maxn],ne[maxn],e[maxn],idx;
int d[maxn],in[maxn],siz[maxn];
int n;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void sol(){
    cin>>n;
    memset(d,0,sizeof d);
    memset(siz,0,sizeof siz);

    for(int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        d[u]++,d[v]++;
    }

    long long ans=0;
    for(int i=1;i<=n;i++){
        if(d[i]>=3){
            ans+=(n-1-d[i]);
        }
    }
    cout<<ans<<endl;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        sol();
    }
    

    return 0;
}
