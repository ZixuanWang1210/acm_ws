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

const int maxn=100;
int dis[maxn][maxn]={0};
int n;

void sol(){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(i==j) continue;
            else cin>>dis[i][j];
            dis[j][i]=dis[i][j];
        }
    }

    int res=dis[1][2];
    for(int i=3;i<=n;i++){
        int t=inf;
        for(int j=1;j<i;j++){
            for(int k=j+1;k<i;k++){
                t=min(t,(dis[i][k]+dis[i][j]-dis[j][k])>>1);
            }
        }
        res+=t;
    }
    cout<<res<<endl;


}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(cin>>n,n){
        sol();
    }

    return 0;
}
