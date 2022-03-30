#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long
using namespace std;



const int maxn=3e6+10;
int h[maxn],ne[maxn],e[maxn],w[maxn],idx;
int n,k;
int dp[maxn][3];

void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=2;i<=n;i++){
        // int u,v,w; cin>>u>>v>>w;
        int f,w; cin>>f>>w;
        add(f,i,w),add(i,f,w);
        if(w==1) dp[i][1]++,dp[f][1]++;
        if(w==2) dp[i][2]++,dp[f][2]++;
    }

    for(int i=1;i<=n;i++){
        for(int ii=h[i];~ii;ii=ne[ii]){
            int j=e[ii];
            if(w[ii]==1) dp[i][2]+=(dp[j][1]-1);
        }
    }

    for(int i=1;i<=n;i++){
        cout<<dp[i][1]+dp[i][2]+1<<endl;
    }
    

    return 0;
}
