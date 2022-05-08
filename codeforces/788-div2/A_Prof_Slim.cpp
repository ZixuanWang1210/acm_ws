#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    int cnt=0;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(v[i]<0) cnt++;
    }
    for(int i=1;i<=n;i++){
        if(i<=cnt) v[i]=0-abs(v[i]);
        else v[i]=abs(v[i]);
    }

    if(is_sorted(v.begin()+1,v.begin()+1+n)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

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
