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
    if(n==3) cout<<"NO"<<endl;
    else if(n%2==0){
        cout<<"YES"<<endl;
        for(int i=1;i<=n/2;i++){
            cout<<"-1 1 ";
        }
        cout<<endl;
        return;
    }
    else{
        cout<<"YES"<<endl;
        for(int i=1;i<=n/2;i++){
            // cout<<"-2 4 ";
            cout<<(n/2)-1<<' '<<-(n/2)<<' ';
        }
        cout<<(n/2)-1;
        cout<<endl;
        return;
    }
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
