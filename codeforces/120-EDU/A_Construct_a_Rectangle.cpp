#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    vector<int> v(4);
    cin>>v[0]>>v[1]>>v[2];
    sort(v.begin(),v.begin()+3);
    if(v[0]+v[1]==v[2]) cout<<"YES"<<endl;
    else {
        if(v[0]==v[1]&&v[2]%2==0){
            cout<<"YES"<<endl;
        }
        else if(v[1]==v[2]&&v[0]%2==0){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }

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
