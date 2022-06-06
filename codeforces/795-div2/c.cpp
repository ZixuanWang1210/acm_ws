#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    s=' '+s;
    int cost1=0,cost2=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='1'){
            cost1=i-1;
            break;
        }
    }
    for(int i=n;i>=1;i--){
        if(s[i]=='1'){
            cost2=n-i;
            break;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='1') cnt++;
    }

    if(cnt==1){
        if(k>=cost2) cout<<1<<endl;
        else if(k>=cost1) cout<<10<<endl;
        else {
            int ans=0;
            for(int i=2;i<=n;i++){
                int a=s[i-1]-'0',b=s[i]-'0';
                ans+=a*10+b;
            }
            cout<<ans<<endl;
        }
    }
    else if(cnt==0){
        cout<<0<<endl;
        return;
    }
    else{
        if(k>=cost1+cost2){
            cout<<cnt*11-11<<endl;
        }
        else if(k>=cost2){
            cout<<cnt*11-10<<endl;
        }
        else if(k>=cost1){
            cout<<cnt*11-1<<endl;
        }
        else{
            int ans=0;
            for(int i=2;i<=n;i++){
                int a=s[i-1]-'0',b=s[i]-'0';
                ans+=a*10+b;
            }
            cout<<ans<<endl;
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
