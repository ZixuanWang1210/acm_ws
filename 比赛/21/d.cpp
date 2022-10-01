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
    int cnt=0;
    stack<char> stk;
    for(auto x:s){
        if(stk.empty()){
            stk.push(x);
            continue;
        }
        char t=stk.top();
        if(x==t) stk.pop(),cnt++;
        else stk.push(x);
    }
    if(cnt&1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
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
