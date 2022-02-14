#include<bits/stdc++.h>
using namespace std;

const int maxn=4000;
int dp[maxn][maxn],a[maxn],b[maxn];
int n;


int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    for(int i=1;i<=n;i++){
        int maxv=1;
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j];
            if(a[i]==b[j]) dp[i][j]=max(dp[i][j],maxv);
            if(b[j]<a[i]) maxv=max(maxv,dp[i-1][j]+1);
        }
    }   

    int res=0;
    for(int i=1;i<=n;i++) res=max(res,dp[n][i]);

    cout<<res<<endl;

    return 0;
}