// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
// #define ll long long
// #define int long long

using namespace std;
string s;

void sol(){
    int len=s.length();
    s=' '+s;

    vector<int> nex(len+1);

    for(int i=2,j=0;i<=len;i++){
        while(j&&s[i]!=s[j+1]) j=nex[j];
        if(s[i]==s[j+1]) j++;
        nex[i]=j;
        // debug(nex[j]);
    }

    if(len%(len-nex[len])==0){
        cout<<len/(len-nex[len])<<endl;
    }
    else cout<<1<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(cin>>s){
        if(s==".") return 0;
        sol();
    }

    return 0;
}
