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
    string s; cin>>s;
    if(s.length()<3){
        cout<<"0"<<endl;
        return;
    }
    int cnt=0;
    for(int i=0;i<s.length()-2;i++){
        // cout<<s[i];
        if(s[i]=='H'&&s[i+1]=='P'&&s[i+2]=='U') cnt++;
    }
    cout<<cnt<<endl;

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
