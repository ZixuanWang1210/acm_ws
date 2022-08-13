#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long
// #define double long double

using namespace std;

void sol(){
    int n; 
    scanf("%d",&n);
    // vector<double> v(n+1);
    double v[n+10];
    long double x_=(double)(1+n)*n/2,y_=0;
    for(int i=1;i<=n;i++) scanf("%lf",&v[i]),y_+=v[i];
    x_/=(long double)n;
    y_/=(long double)n;

    long double fenmu=0;
    for(int i=1;i<=n;i++){
        fenmu+=(i-x_)*(i-x_);
    }
    // cout<<fenmu<<endl;

    long double fenzi=0;
    for(int i=1;i<=n;i++){
        fenzi+=(i-x_)*(v[i]-y_);
    }

    long double k=fenzi/fenmu;

    // double xiyi=0,xi=0,yi=0,xi2=0;
    // for(int i=1;i<=n;i++){
    //     xiyi+=v[i]*i;
    //     xi+=i;
    //     yi+=v[i];
    //     xi2+=i*i;
    // }

    // double k=(xiyi-n*x_*y_)/(xi2-n*x_*x_);

    long double a=y_-k*x_;
    // cout<<a<<' '<<b<<endl;
    // cout<<k<<' '<<b<<endl;
    auto f=[&](int x){
        return (long double)k*x+a;
    };

    double cost=0;

    for(int i=1;i<=n;i++){
        cost+=(v[i]-f(i))*(v[i]-f(i));
    }
    // cout<<fixed<<setprecision(10)<<cost<<endl;
    printf("%.10lf\n",cost);

    // debug(x_);
    // debug(y_);
    // debug(xiyi);


}

signed main(){
    // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;  
    scanf("%d",&_);
    while(_--){
        sol();
    }

    return 0;
}
