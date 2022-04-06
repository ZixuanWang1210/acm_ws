#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    string s; cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='?'){
            if(s[i-1]!='a'&&s[i+1]!='a'){
                s[i]='a';
            }
            // else if(s[i-1]=='a'||s[i+1]=='a'){
            //     s[i]='b';
            // }
            else if(s[i-1]=='a'&&s[i+1]=='b'){
                s[i]='c';
            }
            else if(s[i-1]=='b'&&s[i+1]=='a'){
                s[i]='c';
            }
            else {
                s[i]='b';
            }
        }
        
    }
    cout<<s<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        sol();
    }
    

    return 0;
}
