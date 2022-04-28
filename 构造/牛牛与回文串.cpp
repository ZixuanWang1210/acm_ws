#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long

using namespace std;

void sol(){
    string s; cin>>s;
    // sort(s.begin(),s.end());
    int cnt[30]={0};
    for(int i=0;i<s.length();i++){
        cnt[s[i]-'a']++;
    }
    string res;
    int ttt=0;
    for(int i=0;i<26;i++){
        if(cnt[i]==1) ttt++;
        if(cnt[i]>=2){
            if(cnt[i]&1){
                cnt[i]--;
                for(int j=1;j<=cnt[i]/2;j++){
                    char t=i+'a';
                    res=t+res;
                    res=res+t;
                }
                cnt[i]=1;
                ttt++;
            }
            else{
                for(int j=1;j<=cnt[i]/2;j++){
                    char t=i+'a';
                    res=t+res;
                    res=res+t;
                }
                cnt[i]=0;
            }
        }
    }
    cout<<max(ttt,1ll)<<endl;
    for(int i=0;i<26;i++){
        if(cnt[i]==1){
            char t='a'+i;
            if(res.empty()){
                cout<<t<<endl;
                continue;
            }
            for(int j=0;j<res.length()/2;j++){
                cout<<res[j];
            }
            cout<<t;
            for(int j=res.length()/2;j<res.length();j++){
                cout<<res[j];
            }
            cout<<endl;
            res.clear();
        }
    }
    if(!res.empty()) cout<<res<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
