#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
#define int long long
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n,b,x,y;    
    cin>>n>>b>>x>>y;
    vector<int> v(2*n);
    long long sum=0;
    for(int i=1;i<=n;i++){
        // cin>>v[i];
        if(v[i-1]+x<=b) v[i]=v[i-1]+x;
        else v[i]=v[i-1]-y;
        sum+=v[i];
    }
    cout<<sum<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }
    

    return 0;
}
