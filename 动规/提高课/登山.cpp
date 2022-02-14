#include<bits/stdc++.h>
#define debug_(ch, i) printf(#ch"[%d]: %d\n", i, ch[i])
using namespace std;

const int maxn=2000;
int dp1[maxn],dp2[maxn],ans1[maxn],ans2[maxn];
int dp[maxn][2];
int a[maxn];
int n;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    // for(int i=1;i<=n;i++){
    //     dp1[i]=1;
    //     for(int j=1;j<i;j++){
    //         if(a[j]<a[i]) dp1[i]=max(dp1[i],dp1[j]+1);
    //     }
    //     // debug_(dp1,i);
    // }

    // for(int i=n;i>=1;i--){
    //     dp2[i]=1;
    //     for(int j=n;j>i;j--){
    //         if(a[i]>a[j]) dp2[i]=max(dp2[i],dp2[j]+1);
    //     }
    //     // debug_(dp2,i);
    // }


    // int ans=0;
    // for(int i=1;i<=n;i++){
    //     ans=max(ans,dp1[i]+dp2[i]);
    // }
    // cout<<ans-1;

    for(int i=1;i<=n;i++){
        dp[i][0]=1;
        for(int k=1;k<i;k++){
            if(a[k]<a[i]) dp[i][0]=max(dp[i][0],dp[k][0]+1);
        }
    }


   for(int i=n;i>=1;i--){
        dp[i][1]=1;
        for(int j=n;j>i;j--){
            if(a[i]>a[j]) dp[i][1]=max(dp[i][1],dp[j][1]+1);
        }
    }

    int t=0;
    for(int i=1;i<=n;i++){
        t=max(t,dp[i][0]+dp[i][1]);
    }
    cout<<t-1<<endl;

    return 0;
}