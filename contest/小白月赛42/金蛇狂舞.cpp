#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int jie1[10];
int dp[100];
map<int,int> jie;

void sol(){
    int x,y; cin>>x>>y;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    jie1[1]=1;
    memset(dp,0x3f,sizeof dp);
    for(int i=2;i<=10;i++){
        jie1[i]=jie1[i-1]*i;
        jie[jie1[i]]=i;
    }
    dp[1]=1;
    dp[2]=1;
    cout<<1<<endl;
    for(int i=1;i<=7;i++){
        if(dp[jie[i]]) dp[i]=min(dp[i],dp[jie[i]]+1);
        int t=ceil(sqrt(i));
        dp[i]=min(dp[i],dp[t]+1);
        t=sqrt(i);
        dp[i]=min(dp[i],dp[t]+1);
        cout<<dp[i]<<' ';
    }

    sol();

    return 0;
}
