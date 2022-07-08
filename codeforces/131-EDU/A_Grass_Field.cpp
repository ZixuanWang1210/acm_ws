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
    int a,b,c,d; cin>>a>>b>>c>>d;
    int sum=a+b+c+d;
    if(sum==4){
        cout<<2<<endl;
        return;
    }
    else if(sum==0){
        cout<<0<<endl;
    }
    else cout<<1<<endl;
    //     cout<<2<<endl;
    // }
    // if(sum==0){
    //     cout<<0<<endl;
    // }
    // if(sum==2){
    //     if(a==0&&d==0) cout<<2<<endl;
    //     else if(b==0&&c==0) cout<<2<<endl;
    //     else cout<<1<<endl;
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
