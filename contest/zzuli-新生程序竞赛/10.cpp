#include<bits/stdc++.h>
#define int long long
using namespace std;

const int P=1000000007;
// int n;
const int maxn=1100;
int a[maxn][maxn],s[maxn][maxn];
#define pii pair<int,int>

int _get(pii a,pii b){
    return s[b.first][b.second]-s[a.first-1][b.second]-s[b.first][a.second-1]+s[a.first-1][a.second-1];
}

void sol(){
   int n; cin>>n;
   int ans=0x3f3f3f3f;
   for(int i=1;i<=n;i++){
       for(int j=1;j<=n;j++){
           cin>>a[i][j];
           s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
       }
   }
   for(int i=1;i<=n-2;i++){
       int sum1=s[i][i];
    //    int sum_xia=_get({i+1,i+1},{n,n});
       int sum2=_get({i,i+2},{n,n})+_get({i+2,i},{n,n})-_get({i+2,i+2},{n,n})+a[i+1][i+1];
       ans=min(ans,abs(sum1-sum2));
   }
   cout<<ans;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}