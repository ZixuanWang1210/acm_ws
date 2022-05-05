#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int x,y; cin>>x>>y;
    if(x==y){
        cout<<1<<' '<<1<<endl;
        return ;
    }
    for(int i=2;i<=100;i++){
        int tt=x;
        int cnt=0;
        while(tt<y){
            cnt++;
            tt*=i;
            if(tt==y){
                cout<<cnt<<' '<<i<<endl;
                return;
            }
        }
        
    }
    cout<<"0 0"<<endl;


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
