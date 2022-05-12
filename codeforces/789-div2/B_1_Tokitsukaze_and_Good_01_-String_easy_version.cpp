#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    string s; cin>>s;
    int cnt=0;
    for(int i=0;i<n;i+=2){
        if(s[i]!=s[i+1]) cnt++;
    }

    string tmp;
    for(int i=0;i<n;i+=2){
        if(s[i]==s[i+1]){
            tmp+=s[i];
            tmp+=s[i+1];
        }
    }
    int num=0;
    tmp+=' ';
    for(int i=0;i<tmp.length()-1;i++){
        if(tmp[i]!=tmp[i+1]) num++;
    }
    cout<<cnt<<' '<<(num==0?1:num)<<endl;

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
