#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
int dp[maxn];
int n,m;
int a[maxn];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=a[i];j--){
            dp[j]+=dp[j-a[i]];
        }
    }
    cout<<dp[m];

    return 0;
}