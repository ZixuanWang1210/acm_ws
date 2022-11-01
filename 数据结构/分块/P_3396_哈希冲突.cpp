#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

int n,m;
const int maxn=1000;
int dp[maxn][maxn];
int a[maxn*maxn];

void sol(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sqrt(n);j++){
            dp[j][i%j]+=a[i];
        }
    } 
    while(m--){
        char op; cin>>op;
        if(op=='A'){
            int x,y; cin>>x>>y;
            if(x<=sqrt(n)) cout<<dp[x][y]<<endl;
            else{
                int sum=0;
                for(int i=y;i<=n;i+=x) sum+=a[i];
                cout<<sum<<endl;
            }
        }
        else{
            int x,y; cin>>x>>y;
            for(int i=1;i<=sqrt(n);i++){
                dp[i][x%i]-=(a[x]-y);
            }
            a[x]=y;
        }
    }
    return ;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;`
    while(_--){
        sol();
    }

    return 0;
}
