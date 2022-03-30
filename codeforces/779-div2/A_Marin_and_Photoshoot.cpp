#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n; cin>>n;
    string s; cin>>s;
    int ans=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'&&s[i+1]=='0'&&i+1<=s.length()-1) ans+=2;
        else if(s[i]=='0'&&s[i+1]=='1'&&s[i+2]=='0'&&i+2<=s.length()-1) ans+=1,i+=1;
    }

    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }
    

    return 0;
}
