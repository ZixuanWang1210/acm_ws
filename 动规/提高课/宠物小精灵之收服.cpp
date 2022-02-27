#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

const int maxn=1000+10;
int n,V1,V2;
int dp[maxn][maxn];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>V1>>V2>>n;
    for(int i=0;i<n;i++){
        int v1,v2; cin>>v1>>v2;
        for(int j=V1;j>=v1;j--){
            for(int k=V2-1;k>=v2;k--){
                dp[j][k]=max(dp[j][k],dp[j-v1][k-v2]+1);
            }
        }
    }

    cout<<dp[V1][V2-1]<<' ';
    int k=V2-1;
    while(k>0&&dp[V1][k-1]==dp[V1][V2-1]) k--;
    cout<<V2-k<<endl;
    

    return 0;
}
