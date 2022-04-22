#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n,m; cin>>n>>m;
    if(n>m) swap(n,m);
    if(n==1){
        if(m>2){
            cout<<-1<<endl;
            return;
        }
        else{
            cout<<m-1<<endl;
            return;
        }
    }
    else{
        cout<<(2*n-2)+(m-n)*2-(m-n)%2<<endl;
        return;
    }

    

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
