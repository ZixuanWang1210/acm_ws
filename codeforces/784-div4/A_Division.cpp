#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int x; cin>>x;
    if(x<=1399) cout<<"Division 4";
    else if(x<=1599) cout<<"Division 3";
    else if(x<=1899) cout<<"Division 2";
    else cout<<"Division 1";
    cout<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
