#include <bits/stdc++.h>
#define endl "\n"
// #define debug(x) cout << #x << ": -----> " << x << endl;
typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

ll n;

void sol(){
    ll s,n;
    cin>>n>>s;
    cout<<s/(n*n)<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        sol();
    }
    

    return 0;
}
