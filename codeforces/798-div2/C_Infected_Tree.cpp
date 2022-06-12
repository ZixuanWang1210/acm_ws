#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
// #define int long long

using namespace std;

const int maxn=6e5+10;
int h[maxn],e[maxn],ne[maxn],idx;
int siz[maxn],dp[maxn];
int n;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int dfs(int u,int fa){
    siz[u]=1;
    int s1=-1,s2=-1;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,u);
        siz[u]+=siz[j];
        if(s1==-1) s1=j;
        else if(s2==-1) s2=j;
    }
    if(s1==-1) dp[u]=0;
    else if(s2==-1) dp[u]=siz[s1]-1;
    else dp[u]=max(siz[s1]-1+dp[s2],siz[s2]-1+dp[s1]);
    return dp[u];
    
}

void sol(){
    cin>>n;
    for(int i=0;i<=n;i++){
        h[i]=-1;
    }
    for(int i=0;i<n-1;i++){
        int a,b; cin>>a>>b;
        add(a,b),add(b,a);
    }
    cout<<dfs(1,-1)<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
