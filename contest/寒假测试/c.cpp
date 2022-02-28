#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n;
string s;

bool check(){
    for(int i=0;i<s.length();i++){
        if(s[i]=='z'&&s[i+1]=='f'&&s[i+2]=='c'){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    int cnt=0;
    while(!check()){
        // cnt++;
        for(int i=0;i<s.length();i++){
            if(s[i]=='z'&&s[i+1]=='f'&&s[i+2]=='c'){
                s.erase(s.begin()+i,s.begin()+i+3);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;

    return 0;
}
