#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    int cnt[30]={0};
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        for(int j=0;j<s1.length();j++){
            cnt[s1[j]-'a']++;
        }
        for(int j=0;j<s2.length();j++){
            cnt[s2[j]-'a']++;
        }
    }
    string s; cin>>s;
    for(int j=0;j<s.length();j++){
        cnt[s[j]-'a']++;
    }
    for(int i=0;i<26;i++){
        if(cnt[i]%2!=0&&cnt[i]!=0){
            char ans='a'+i;
            cout<<ans<<endl;
            return ;
        }
    }

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
