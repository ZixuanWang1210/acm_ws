#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 2e6
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
// #define int long long

using namespace std;

#define pdd pair<double,double>
int n;
double ans=inf;
vector<pdd> a;

double rand(double l,double r){
    return (double) rand()/RAND_MAX*(r-l)+l;
}

double get(pdd a,pdd b){
    double da=a.first-b.first;
    double db=a.second-b.second;
    return sqrt(da*da+db*db);
}

double get_now(pdd &p){
    double res=0;
    for(auto x:a){
        res+=get(p,x);
    }
    ans=min(ans,res);
    return res;
}

void sa(){
    pdd p(rand(0,1e4),rand(0,1e4));
    for(double t=1e4;t>1e-4;t*=0.99){
        pdd np(rand(p.first-t,p.first+t),rand(p.second-t,p.second+t));
        double dt=get_now(np)-get_now(p);
        if(exp(-dt/t)>rand(0,1)) p=np;
    }
}

void sol(){
    cin>>n;
    a.resize(n);
    srand((unsigned)time(NULL));
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    for(int i=0;i<100;i++){
        sa();
    }
    cout<<round(ans)<<endl;

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
