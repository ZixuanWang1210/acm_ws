#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
// #define int long long

using namespace std;

const int maxn=1100;
double d[maxn][maxn],x[maxn],y[maxn],t[maxn],r[maxn];
int n;

void sol(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i]>>t[i]>>r[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            double dx=x[i]-x[j];
            double dy=y[i]-y[j];
            d[i][j]=sqrt(dx*dx+dy*dy)/min(t[i],r[j]);
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    double res=0;
    sort(d[0],d[0]+n);
    for(int i=1;i<n;i++){
        res=max(res,d[0][i]+(n-1-i));
    }
    cout<<res<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
