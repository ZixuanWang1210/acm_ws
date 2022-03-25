#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

int lowbit(int x){
    return x&-x;
}

void sol(){
    int n; cin>>n;
    int nn=2;
    if(n-lowbit(n)==0){
        cout<<-1<<endl;
        return;
    }
    else{
        if(n&1) cout<<2<<endl;
        else {
            while(n%2==0){
                n/=2;
                nn<<=1;
            }
            cout<<min(n,nn)<<endl;
        }
    }
    return;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
