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
    string s; cin>>s;
    vector<char> v;
    int cnt=0,wh=0;

    for(auto x:s){
        if(x=='(') cnt++;
        else if(x==')') cnt--;
        else if(x=='?') wh++;
        if(cnt+wh==1){
            cnt=1;
            wh=0;
        }
    }
    cout<<(wh==cnt?"YES":"NO")<<endl;

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
