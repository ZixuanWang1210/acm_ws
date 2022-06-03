#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

const int maxn=210;
int a[maxn];
int g[maxn][maxn];

void sol(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }    
    for(int len=3;len<=n+1;len++){
        for(int i=1;i+len-1<=n*2;i++){
            int l=i,r=i+len-1;
            for(int k=l+1;k<r;k++){
                g[l][r]=max(g[l][r],g[l][k]+g[k][r]+a[l]*a[k]*a[r]);
            }
        }
    }
    int maxn=-0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        maxn=max(g[i][i+n],maxn);
    }
    cout<<maxn<<endl;
    return ;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
