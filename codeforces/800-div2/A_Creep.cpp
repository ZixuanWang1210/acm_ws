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
    int a,b; cin>>a>>b;
    int res=abs(a-b);
    for(int i=1;i<=min(a,b);i++){
        cout<<10;
    }
    if(a>b){
        for(int i=1;i<=res;i++){
            cout<<0;
        }
    }
    else{
        for(int i=1;i<=res;i++){
            cout<<1;
        }
    }
    cout<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
