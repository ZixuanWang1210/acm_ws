#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

const int maxn=1e5+10;
int dp[maxn];
int m,n,c;
int v[maxn],w[maxn];


void sol(){
    cin>>m>>n>>c; 
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=c;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }

    bool ok=false;
    int k=0;
    for(int i=0;i<=c;i++){
        if(dp[i]>=m){
            ok=true;
            k=i;
            break;
        }
    }
    if(!ok) cout<<"Impossible"<<endl;
    else cout<<c-k<<endl;


}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
