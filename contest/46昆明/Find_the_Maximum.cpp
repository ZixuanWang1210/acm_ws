//https://ac.nowcoder.com/acm/contest/view-submission?submissionId=51882348
#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

const int maxn=3e5+10;
int h[maxn],e[maxn],ne[maxn],idx;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

double v[maxn];

double dfs(int u,int fa){
    double ans=0;
    double mx=0,mi=0;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        ans=max(ans,max(abs(v[u]+v[j]+v[fa])/3,abs(v[u]+v[j])/2));
        ans=max(ans,max(abs(mx+v[j]+v[u]),abs(mi+v[j]+v[u]))/3);

        mx=max(mx,v[j]);
        mi=min(mi,v[j]);
        ans=max(ans,dfs(j,u));
    }
    return ans;
}

void sol(){
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>v[i];
    memset(h,-1,sizeof h);
    for(int i=1;i<=n-1;i++){
        int u,v; cin>>u>>v;
        add(u,v),add(v,u);
    }
    double ans=dfs(1,0)/2;
    cout<<fixed<<setprecision(6)<<ans*ans<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
