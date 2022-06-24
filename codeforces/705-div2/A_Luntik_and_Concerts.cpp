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
    int a,b,c;  cin>>a>>b>>c;
    // a=a&1;
    // b=b&1;
    // c=c&1;
    // if(a==1&&b==1&&c==1){
    //     cout<<"0"<<endl;
    //     return;
    // }
    // else if(a==1&&b==1){
    //     cout<<'1'<<endl;
    //     return;
    // }
    // else if(a==1&&c==1){
    //     cout<<2<<endl;
    //     return;
    // }
    // else if(b==1&&c==1){
    //     cout<<1<<endl;
    //     return;
    // }
    // else {
        cout<<(a+c)%2<<endl;
        return;
    // }
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
