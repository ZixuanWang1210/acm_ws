#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int long long
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int a,b; cin>>a>>b;
    if(a==0){
        cout<<1<<endl;
        return;
    }
    else{
        cout<<2*b+a+1<<endl;
        return;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        sol();
    }
    

    return 0;
}
