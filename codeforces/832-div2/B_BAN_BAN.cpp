#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    if(n==1){
        cout<<1<<endl;
        cout<<"1 2"<<endl;
        return;
    }
    cout<<(n+1)/2<<endl;
    for(int i=1,j=3*n;i<=j;i+=3,j-=3){
        cout<<i<<' '<<j<<endl;
    }
    return;

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