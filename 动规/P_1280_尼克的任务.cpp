#include<bits/stdc++.h>
using namespace std;

int n,k;
const int maxn=3e6+10;
vector<int> v[maxn];
int dp[maxn];

int main(){
    memset(dp,-0x3f3f3f3f,sizeof dp);
    cin>>n;
    int st=0x3f3f3f3f,ed=-0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        int p,t; cin>>p>>t;
        v[p].push_back(t-p);
        st=min(st,p),ed=max(ed,t);
    }
    // cout<<st<<' '<<ed;
    dp[st]=0;
    for(int i=st;i<=ed;i++){
        if(v[i].size()==0){
            dp[i+1]=max(dp[i]+1,dp[i+1]);
        }
        else{
            // for(int j=0; j<v[i].size(); ++j) {
            //     int &x=dp[i+v[i][j]];
            //     x=max(x, dp[i]);
            // }
            for(auto x:v[i]){
                dp[i+x]=max(dp[i+x],dp[i]);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<dp[i]<<' ';
    // }
    cout<<dp[ed+1]+1<<endl;

    return 0;
}