#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n,k; cin>>n>>k;
    for(int i=1;i<=k;i++){
        if(i==k){
            cout<<(n-i+1)<<' '<<1<<endl;
        }
        else{
            cout<<i<<' '<<0<<endl;
        }
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
