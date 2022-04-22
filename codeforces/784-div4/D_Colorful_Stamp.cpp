#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    string s; cin>>s;
    s='W'+s+'W';
    int re=-1;
    int cnt_b=0,cnt_r=0;

    for(int i=0;i<s.length();i++){
        if(s[i]=='W'){
            int len=i-re;
            if(len<3&&len!=1){
                cout<<"NO"<<endl;
                return;
            }
            else if((cnt_b==0||cnt_r==0)&&len!=1){
                cout<<"NO"<<endl;
                return;
            }
            cnt_b=0,cnt_r=0;
            re=i;
        }
        if(s[i]=='B') cnt_b++;
        if(s[i]=='R') cnt_r++;
    }

    cout<<"YES"<<endl;
    return;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
