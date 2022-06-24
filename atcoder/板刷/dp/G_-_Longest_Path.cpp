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
int h[maxn],e[maxn],ne[maxn],idx;
int n,m;
int din[maxn],dout[maxn];
int dp[maxn];

void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void sol(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++){
        int x,y; cin>>x>>y;
        add(x,y);
        dout[x]++,din[y]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(din[i]==0){
            q.push(i);
            dp[i]=1;
        }
    }

    while(q.size()){
        int ver=q.front();
        q.pop();

        for(int i=h[ver];~i;i=ne[i]){
            int j=e[i];
            dp[j]=max(dp[j],dp[ver]+1);
            din[j]--;
            if(din[j]==0) q.push(j);
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans-1<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
