#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    string s;
    cin>>s;
    int len=s.length();
    int ans=0;
    for(int i=0;i<len;i++){
        ans+=(s[i]-'a')+1;
    }
    // cout<<ans<<endl;
    if(len%2==0){
        cout<<"Alice ";
        cout<<ans<<endl;
        return;
    }
    else{
        int ans2=0;
        if(s[0]<s[len-1]) ans-=(s[0]-'a')+1,ans2=(s[0]-'a')+1;
        else ans-=(s[len-1]-'a')+1,ans2=(s[len-1]-'a')+1;
        // cout<<ans<<' '<<ans2<<endl;
        if(ans>ans2){
            cout<<"Alice "<<ans-ans2<<endl;
        }
        else cout<<"Bob "<<ans2-ans<<endl;
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
