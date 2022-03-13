#include<bits/stdc++.h>
#define int long long
using namespace std;

const int P=1000000007;
// int n;

void sol(){
    int len; cin>>len;
    len=3;
    string s; cin>>s;
    map<string,char> mp;
    int idx='a';
    for(int i=0;i<s.length();i=i+len){
        string ns;
        for(int j=i;j<i+len;j++){
            ns+=s[j];
        }
        if(mp[ns]!=0){
            cout<<mp[ns];
        }
        else{
            if(idx=='z'+1) idx='A';
            mp[ns]=idx;
            idx++;
            cout<<mp[ns];
        }
    }
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}