#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

const int maxn=5100;
pii in[maxn];
int a[maxn],dp[maxn];
int n;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b; cin>>a>>b;
        in[i]={a,b};
    }

    sort(in+1,in+1+n);

    for(int i=1;i<=n;i++){
        int t=in[i].second;
        a[i]=in[i].second;
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=1;j<i;j++){
            if(a[j]<a[i]) dp[i]=max(dp[i],dp[j]+1);
        }
        ans=max(ans,dp[i]);
    }

    cout<<ans;

    return 0;
}