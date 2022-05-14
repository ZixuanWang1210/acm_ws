#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        sum+=v[i];
    }

    if(sum%n) cout<<1<<endl;
    else cout<<0<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
