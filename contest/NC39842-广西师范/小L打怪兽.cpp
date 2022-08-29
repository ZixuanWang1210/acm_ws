#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

const int maxn=5000;
int dp[maxn][maxn];
int n,m,K;
int v[maxn],w[maxn];


void sol(){
    cin>>K>>m>>n;
    memset(dp,-0x3f,sizeof dp);
    dp[0][1]=0;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];

    for(int i=1;i<=n;i++){
        for(int j=v[i];j<=m;j++){
            int tmp[K+10]={0};

            int p1=1,p2=1;
            for(int k=1;k<=K;k++){
                if(dp[j][p1]>=dp[j-v[i]][p2]+w[i]) tmp[k]=dp[j][p1],p1++;
                else tmp[k]=dp[j-v[i]][p2]+w[i],p2++;
            }

            for(int i=1;i<=K;i++){
                dp[j][i]=tmp[i];
            }
        }
    }    

    int res=dp[m][K];
    if(res<0) res=-1;
    cout<<res<<endl;
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
