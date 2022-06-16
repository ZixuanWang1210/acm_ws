#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
// #define int long long

using namespace std;

void sol(){
    int a,b,x; cin>>a>>b>>x;

    for(int i=0;i<=100000;i++){
        int res=x-i*a;
        if(res<0) break;
        if(res%b==0){
            cout<<i<<' '<<res/b<<endl;
            return;
        }
    }
    cout<<-1<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
