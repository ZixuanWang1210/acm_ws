#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;


double get(double x0, double y0){
    return sqrt(x0*x0+y0*y0);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    double x,y,x0,y0;

    cin>>n;
    cin>>x0>>y0>>x>>y;
    x0-=x,y0-=y;
    double ans=get(x0,y0);
    for(int i=0;i<n;i++){
        double xx,yy;cin>>xx>>yy;
        ans=min(ans,get(x0+xx,y0+yy));

    }
    cout<<fixed<<setprecision(8)<<ans;
    return 0;
}
