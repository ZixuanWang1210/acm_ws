#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    string s; cin>>s;
    set<char> ss;
    for(int i=0;i<s.length();i++){
        char t; t=s[i];
        if(t>='a'&&t<='z'){
            ss.insert(t);
        }
        else{
            t=t+('a'-'A');
            // cout<<t<<endl;
            if(ss.count(t)==0){
                cout<<"NO"<<endl;
                return ;
            }
        }
    }

    cout<<"YES"<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }
    

    return 0;
}
