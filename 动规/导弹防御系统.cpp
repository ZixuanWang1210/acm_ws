#include<bits/stdc++.h>
using namespace std;

const int maxn=60;
int dp[maxn],up[maxn],down[maxn],a[maxn];
int n,ans;

void dfs(int u,int su,int sd){
    if(su+sd>=ans) return ;
    if(u==n){
        ans=min(ans,su+sd);
    }


    int k=0;
    while(k<su&&up[k]>=a[u]) k++;
    if(k<su){
        int t=up[k];
        up[k]=a[u];
        dfs(u+1,su,sd);
        up[k]=t;
    }
    else{
        up[k]=a[u];
        dfs(u+1,su+1,sd);
    }

    k=0;
    while(k<sd&&down[k]<=a[u]) k++;
    if(k<sd){
        int t=down[k];
        down[k]=a[u];
        dfs(u+1,su,sd);
        down[k]=t;
    }
    else{
        down[k]=a[u];
        dfs(u+1,su,sd+1);
    }
}

int main(){
    while(cin>>n,n){
        memset(a,0,sizeof a);
        for(int i=0;i<n;i++) cin>>a[i];

        ans=n;
        dfs(0,0,0);

        cout<<ans<<endl;;

    }

    return 0;
}