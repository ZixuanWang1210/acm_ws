#include<bits/stdc++.h>
using namespace std;

int n,T;
const int maxn=300;
int a[maxn],dp[maxn];

int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];

        int res=0;
        for(int i=1;i<=n;i++){
            dp[i]=1;
            for(int k=1;k<i;k++){
                if(a[k]<a[i]) dp[i]=max(dp[i],dp[k]+1);
                // else dp[i]=max(1,dp[i]);
            }
            res=max(res,dp[i]);
        }
        // cout<<res<<endl;
        for(int i=n;i;i--){
            dp[i]=1;
            for(int j=n;j>i;j--){
                if(a[i]>a[j])
                    dp[i]=max(dp[i],dp[j]+1);
                // else dp[i]=max(1,dp[i]);
            }
            res=max(res,dp[i]);
        }
        cout<<res<<endl;
    }

    return 0;
}