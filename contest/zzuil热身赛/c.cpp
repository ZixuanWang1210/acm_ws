#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long
using namespace std;

int x,y,z;

void sol(){
    cin>>x>>y>>z;
    int l=x*x+y*y+z*z;
    int r=3*x*y*z;

    if(r==l) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        sol();
    }    

    return 0;
}
