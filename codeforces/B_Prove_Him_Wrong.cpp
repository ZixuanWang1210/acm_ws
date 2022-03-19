#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define int long long
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;


long long b[100];
void biao(){
    b[0]=1;
    for(int i=1;i<=20;i++){
        b[i]=b[i-1]*3;
        // if(b[i]>1e9) break;
        // cout<<i<<' '<<b[i]<<endl;
    }
}

void sol(){
    int n; cin>>n;
    if(n>=20){
        cout<<"NO"<<endl;
        return;
    }
    else{
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            cout<<b[i]<<' ';
        }
        cout<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    biao();
    int _; cin>>_;
    while(_--){
        sol();
    }
    

    return 0;
}
