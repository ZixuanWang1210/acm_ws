#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
// #define ll long long
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1);
    vector<int> res;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(v[i]!=i-1) res.push_back(v[i]);
    }

    for(int i=0;i<res.size()-1;i++){
        res[i+1]&=res[i];
    }
    cout<<res[res.size()-1]<<endl;

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
