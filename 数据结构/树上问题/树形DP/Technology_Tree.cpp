#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

int n,q;
const int maxn=2e5+10;
int h[maxn],e[maxn],w1[maxn],w2[maxn],ne[maxn],idx;
int dp1[maxn],dp2[maxn];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int fa){
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dp1[j]=dp1[u]+w1[j];
        dp2[j]=dp2[u]+w2[j];
        dfs(j,u);
    }
}

void sol(){
    cin>>n>>q;
    for(int i=1;i<=n*4;i++){
        w1[i]=w2[i]=e[i]=ne[i]=0;
        dp1[i]=dp2[i]=0;
        h[i]=-1;
    }
    for(int i=1;i<=n;i++){
        cin>>w1[i]>>w2[i];
    }

    for(int i=1;i<=n-1;i++){
        int a; cin>>a;
        add(a,i+1);
    }
    dp1[1]=w1[1],dp2[1]=w2[1];
    dfs(1,0);


    while(q--){
        int x; cin>>x;
        cout<<dp1[x]<<' '<<dp2[x]<<endl;
    }



}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
