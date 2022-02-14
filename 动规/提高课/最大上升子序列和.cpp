#include<bits/stdc++.h>
using namespace std;

const int maxn=2000;
int n;
int dp[maxn],a[maxn];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    int ans=0;
    for(int i=1;i<=n;i++){
        dp[i]=a[i];
        for(int k=1;k<i;k++){
            if(a[k]<a[i]) dp[i]=max(dp[i],dp[k]+a[i]);
        }
        ans=max(ans,dp[i]);
    }

    cout<<ans;

    return 0;
}