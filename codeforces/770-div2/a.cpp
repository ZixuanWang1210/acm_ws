#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

string s;

bool check(){
    // for(int i=0;i<s.length();i++){
    //     for(int j=s.length()-1;j>=i;j--){
    //         if(s[i]!=s[j]) return false;
    //     }
    // }
    // return true;
    string ss;
    ss=s;
    reverse(ss.begin(),ss.end());
    // cout<<ss<<" "<<s<<endl;
    if(ss==s) return true;
    else return false;
}

void sol(){
    int len,k;
    cin>>len>>k; cin>>s;

    if(k==0||check()==true){
        cout<<1<<endl;
        return;
    }
    else{
        cout<<2<<endl;
        return;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        sol();
    }
    

    return 0;
}
