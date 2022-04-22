#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v1,v2;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        if(i&1) v1.push_back(x);
        else v2.push_back(x);
    }
    for(int i=0;i<v1.size()-1;i++){
        if((v1[i]&1)!=(v1[i+1]&1)){
            cout<<"NO"<<endl;
            return;
        }
    }
    for(int i=0;i<v2.size()-1;i++){
        if((v2[i]&1)!=(v2[i+1]&1)){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
