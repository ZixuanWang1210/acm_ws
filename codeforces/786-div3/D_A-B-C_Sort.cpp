#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=n;i>=1;i-=2){
        if(v[i]<v[i-1]) swap(v[i],v[i-1]);
    }
    if(is_sorted(v.begin()+1,v.begin()+1+n)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return;
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
