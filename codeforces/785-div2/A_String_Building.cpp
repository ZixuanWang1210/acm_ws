#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    string s; cin>>s;
    int len=s.length()-1;
    if((s[len]=='b'&&s[len-1]!='b')||(s[len]=='a'&&s[len-1]!='a')||len==0){
        cout<<"NO"<<endl;
        return;
    }
    if((s[0]=='b'&&s[1]!='b')||(s[0]=='a'&&s[1]!='a')){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='b'&&s[i+1]=='a'&&s[i+2]=='b'){
            cout<<"NO"<<endl;
            return;
        }
        else if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='a'){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
