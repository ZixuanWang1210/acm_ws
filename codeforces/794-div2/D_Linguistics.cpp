#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

bool sol(){
    int a,b,c,d; cin>>a>>b>>c>>d;
    string s; cin>>s;
    string ans;
    for(int i=0;i<s.length();i++){
        if(s[i]==s[i+1]=='A') {
            ans+="A";
            a--;
            if(a<0) return false;
        }
        else if(s[i]==s[i+1]=='B'){
            ans+="B";
            a--;
            if(b<0) return false;
        }
        if(s[i]=='A'&&s[i+1]=='B'){
            if(c){
                ans+="AB";
                c--;
            }
            else{
                ans+="AB";
                a--,b--;
                if(a<0||b<0) return false;
            }
        }
        if(s[i]=='B'&&s[i+1]=='A'){
            if(d){
                ans+="BA";
                c--;
            }
            else{
                ans+="BA";
                a--,b--;
                if(a<0||b<0) return false;
            }
        }
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        if(sol()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
