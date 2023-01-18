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

using namespace std;

void sol(){
    int x,y,xp,yp;
    cin>>x>>y>>xp>>yp;
    vector<pii> v;
    v.push_back({0,0});
    v.push_back({0,y});
    v.push_back({x,y});
    v.push_back({x,0});
    int s1=x*y;
    double ans=0;
    for(auto m:v){
        int nowx1=min(m.first,xp);int nowy1=min(m.second,yp);
        int nowx2=max(m.first,xp);int nowy2=max(m.second,yp);
        int s2=(nowx1-nowx2)*(nowy1-nowy2);
        int a3=max(nowx1,0);
        int c3=min(nowx2,x);
        int b3=max(nowy1,0);
        int d3=min(nowy2,y);
        int s3=(a3-c3)*(b3-d3);
        double res=1.0*s3/(s1+s2-s3);
        ans=max(ans,res);
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
