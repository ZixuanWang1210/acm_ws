#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

const int maxn=2e6+10;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
int n,m;
double dp[maxn];
int dout[maxn];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

double f(int u){
    if(dp[u]>=0) return dp[u];
    dp[u]=0;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        dp[u]+=(w[i]+f(j))/dout[u];
    }
    return dp[u];
}

void sol(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int a,b,c; cin>>a>>b>>c;
        add(a,b,c);
        dout[a]++;
    }

    memset(dp,-1,sizeof dp);

    printf("%.2lf\n",f(1));

}

signed main(){
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
