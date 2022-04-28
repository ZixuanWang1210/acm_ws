#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n ;cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=2;i<=n;i++){
        if(v[i]==v[i-1]){
            cout<<-1<<endl;
            return;
        }
        else if(__gcd(v[i],v[i-1])!=1){
            cout<<-1<<endl;
            return;
        }
    }
    cout<<0<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
