#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int long long
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(2*n);
    int d1=0,d2=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(v[i]>=d1) d2=d1,d1=v[i];
        else if(v[i]>=d2) d2=v[i];
    }
    if(d1-d2>=2){
        cout<<"NO"<<endl;
        return ;
    }
    cout<<"YES"<<endl;
    return ;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        sol();
    }
    

    return 0;
}
