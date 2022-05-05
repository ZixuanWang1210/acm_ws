#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

void sol(){
    int i=0,j=0;
    string s; cin>>s;

    int len=s.length();
    int cnt[5]={0};

    int res=0x3f3f3f3f;
    while(j<len){
        cnt[s[j]-'0']++;
        while(cnt[1]&&cnt[2]&&cnt[3]&&i<j){
            res=min(res,j-i+1);
            cnt[s[i]-'0']--,i++;
        }    
        j++;
    }
    if(res!=0x3f3f3f3f) cout<<res<<endl;
    else cout<<0<<endl;

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
