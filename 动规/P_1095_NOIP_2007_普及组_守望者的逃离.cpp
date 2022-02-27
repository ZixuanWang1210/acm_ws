#include<bits/stdc++.h>
using namespace std;

int m,s,t;
const int maxn=3e5+10;
int dp[maxn];


int main(){
    cin>>m>>s>>t;
    for(int i=1;i<=t;i++){
        if(m>=10) dp[i]=dp[i-1]+60, m-=10;
        else dp[i]=dp[i-1], m+=4;
    }
    for(int i=1;i<=t;i++){
        if(dp[i]<dp[i-1]+17) dp[i]=dp[i-1]+17;
        if(dp[i]>=s) {cout<<"Yes"<<endl<<i<<endl; return 0;}
    }
    cout<<"No"<<endl<<dp[t]<<endl;
    return 0;
}