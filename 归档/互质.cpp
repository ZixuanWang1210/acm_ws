#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

void sol(){
    int x; cin>>x;
    if(x==6){
        cout<<-1<<endl;
        return;
    }
    if(x%2==0){
        if((x-2)%4==0) cout<<x/2-2<<endl;
        else cout<<x/2-1<<endl;
        return;
    }
    else cout<<x/2<<endl;

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
