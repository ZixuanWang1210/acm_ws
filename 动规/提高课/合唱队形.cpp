#include<bits/stdc++.h>
using namespace std;

const int maxn=300;
int a[maxn],dp[maxn][2];
int n;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++){
        dp[i][0]=1;
        for(int k=1;k<i;k++){
            if(a[k]<a[i]) dp[i][0]=max(dp[i][0],dp[k][0]+1);
        }
    }

    // for(int i=1;i<=n;i++){
    //     dp[i][1]=1;
    //     for(int k=1;k<i;k++){
    //         if(a[k]>a[i]) dp[i][1]=max(dp[i][1],dp[k][1]+1);
    //     }
    // }

   for(int i=n;i>=1;i--){
        dp[i][1]=1;
        for(int j=n;j>i;j--){
            if(a[i]>a[j]) dp[i][1]=max(dp[i][1],dp[j][1]+1);
        }
        // debug_(dp2,i);
    }

    int t=0;
    for(int i=1;i<=n;i++){
        t=max(t,dp[i][0]+dp[i][1]);
    }
    cout<<n-t+1<<endl;

    return 0;
}