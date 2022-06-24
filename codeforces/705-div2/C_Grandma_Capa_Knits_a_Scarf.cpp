#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
// #define ll long long
#define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    string s; cin>>s;
        string ss=s;
        reverse(_all(ss));
        int ans=inf;
        for(char ch='a';ch<='z';ch++){
            int len=0;
            bool ok=true;
            for(int i=0,j=0;i+j<n;){
                if(s[i]==ss[j]) i++,j++;
                else if(ss[j]==ch) j++,len++;
                else if(s[i]==ch) i++,len++;
                else{
                    // len=-1;
                    ok=false;
                    break;
                }
            }
            if(ok) ans=min(ans,len);
        }
        if(ans==inf){
            cout<<-1<<endl;
            return;
        }
        else{
            cout<<ans<<endl;
            // cout<<n-ans<<endl;
        }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
