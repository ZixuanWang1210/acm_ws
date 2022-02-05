#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int N=1e4+10;
int n,m,W;
int f[N],w[N],v[N];
int dp[N];

int find(int x){
    if(x!=f[x]){
        f[x]=find(f[x]);
    }
    return f[x];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>W;
    for(int i=1;i<=n;i++){
        f[i]=i;
        cin>>v[i]>>w[i];
    }

    while(m--){
        int x,y;cin>>x>>y;
        x=find(x),y=find(y);
        if(x!=y){
            v[x]+=v[y];
            w[x]+=w[y];
            f[y]=x;
        }
    }

    for(int i=1;i<=n;i++)
        if(f[i]==i)
            for(int j=W;j>=v[i];j--)
                dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
            
    cout<<dp[W];


    

    return 0;
}
