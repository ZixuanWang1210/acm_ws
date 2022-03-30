#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define P 998244353
#define int long long
using namespace std;

bool judge(int x){
    // if(x<2) return false;
    for(int i=2;i<=x/i;i++){
        if(x%i==0) return false;
    }
    return true;
}

void sol(){
    int n; cin>>n;
    // if(n==1){
    //     cout<<0<<endl;
    //     return;
    // }
    // if(n==2){
    //     cout<<1<<endl;
    //     return;
    // }
    
    // if(judge(n)){
    //     cout<<0<<endl;
    //     return;
    // }
    // else{
    //     cout<<n*n%P<<endl;
    // }
    if(n&1){
        cout<<0<<endl;
        return;
    }
    else{
        n/=2;
        int res=1;
        for(int i=1;i<=n;i++){
            res=res*i%P;
        }
        cout<<res*res%P<<endl;
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
