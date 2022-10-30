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
    string s[5]={"1001", "10001", "100110", "1001010"};
    int n; cin>>n;
    if(n==2) cout<<"10"<<endl;
    else if(n==3) cout<<"Unlucky"<<endl;
    else if(n==4) cout<<"1000"<<endl;
    else if(n<=7) cout<<s[n-4]<<endl;
    else {
        for(int i=1;i<=((n-4))/4;i++) cout<<s[0];
        cout<<s[(n-4)%4]<<endl;
    }

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
