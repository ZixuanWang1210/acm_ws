#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int a,b,x; cin>>a>>b>>x;
    x/=2;
    if((a-x)&1||(b-x)&1){
        cout<<-1<<endl;
        return;
    }
    else if(x>a||x>b){
        cout<<-1<<endl;
        return;
    }
    else{
        for(int i=1;i<=x;i++){
            cout<<"01";
        }
        for(int i=x+1;i<=a;i++){
            cout<<0;
        }
        for(int i=x+1;i<=b;i++){
            cout<<1;
        }
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
