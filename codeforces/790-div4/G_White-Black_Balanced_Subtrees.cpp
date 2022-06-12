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

const int maxn=2e5+10;
int ne[maxn],e[maxn],h[maxn],idx;
int n;
int cntw[maxn],cntb[maxn];
int ans=0;
string s;

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u,int fa){
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        dfs(j,u);
        cntb[u]+=cntb[j];
        cntw[u]+=cntw[j];
    }
    if(cntw[u]==cntb[u]) {
        // debug(u);
        ans++;
    }
}

void sol(){
    cin>>n;
    ans=0;
    idx=0;
    for(int i=0;i<=n;i++){
        h[i]=-1;
        cntw[i]=cntb[i]=0;
    }
    for(int i=2;i<=n;i++){
        int x; cin>>x;
        add(i,x),add(x,i);
    }

    cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++){
        if(s[i]=='W') cntw[i]=1;
        else cntb[i]=1;
    }
    dfs(1,-1);

    cout<<ans<<endl;

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
