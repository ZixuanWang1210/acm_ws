#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int r,h; cin>>r>>h;
    int cnt=h/(2*r);
    double v1=(double)4/3*r*r*r*cnt*3.141592653589;
    double v2=(double)3.141592653589*r*r*h;
    cout<<fixed<<setprecision(3)<<v2-v1<<endl;
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        sol();
    }
    

    return 0;
}
