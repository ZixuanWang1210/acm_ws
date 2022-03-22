#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    string s; cin>>s;
    map<int,int> mp;
    for(int i=0;i<s.length();i++){
        int idx=s[i]-'a';
        mp[idx]++;
    }
    for(int i=0;i<s.length();i++){
        int idx=s[i]-'a';
        if(mp[idx]>1){
            mp[idx]--;
        }else{
            while(i<s.length()){
                cout<<s[i];
                i++;
            }
        }
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }
    

    return 0;
}
