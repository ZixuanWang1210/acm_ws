#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long
 
using namespace std;
 
int n,m;
const int maxn=2e3+10;
int a[maxn*maxn];
int dp[maxn][maxn];
 
 
void sol(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
 
    if(n>m){
        cout<<"xiao lan"<<endl;
        return;
    }
 
    dp[0][0]=1;
    bool flag=false;
    for(int i=1;i<=n;i++){
        for(int j=m-1;j>=0;j--){
            int x=((j-a[i])%m+m)%m;
            if(dp[i-1][x]){
                dp[i][j]=1;
                if(j==0) flag=true;
            }
            if(dp[i-1][j]) dp[i][j]=1;
        }
    }
    if(flag) cout<<"xiao lan"<<endl;
    else cout<<"xiao hong"<<endl;
 
}
 
signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
    int _=1;
    while(_--){
        sol();
    }
 
    return 0;
}
