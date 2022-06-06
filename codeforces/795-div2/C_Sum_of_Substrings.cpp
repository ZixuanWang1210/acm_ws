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

    int cnt1=0,cnt0=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='1') cnt1++;
        else cnt0++;
    }
    int cnt=0;
    int max1=0,max2=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='1'){
            max1+=(i-cnt-1);
            cnt++;
        }
    }
    cnt=0;
    for(int i=n;i>=1;i--){
        if(s[i]=='1'){
            max2+=(n-i-cnt);
            cnt++;
        }
    }
    if(k>=max2){
        s=' ';
        for(int i=1;i<=cnt0;i++){
            s=s+'0';
        }
        for(int i=1;i<=cnt1;i++){
            s=s+'1';
        }
        // cout<<s<<endl1;
        int ans=0;
        for(int i=2;i<=n;i++){
            int a=s[i-1]-'0',b=s[i]-'0';
            ans+=a*10+b;
        }
        cout<<ans<<endl;
        return;
    }
    else if(k>=max1){
        s=' ';
        for(int i=1;i<=cnt1;i++){
            s=s+'1';
        }
        for(int i=1;i<=cnt0;i++){
            s=s+'0';
        }
        // cout<<s<<endl;
        int ans=0;
        for(int i=2;i<=n;i++){
            int a=s[i-1]-'0',b=s[i]-'0';
            ans+=a*10+b;
        }
        cout<<ans<<endl;
        return;
    }


    for(int i=3;i<=n;i++){
        if(s[i-2]=='1'&&s[i-1]=='0'&&s[i]=='1'){
            if(k){
                k--;
                s[i-1]='1';
                s[i]='0';
            }
        }
    }
    int ans=0;
    for(int i=2;i<=n;i++){
        int a=s[i-1]-'0',b=s[i]-'0';
        ans+=a*10+b;
    }
    cout<<ans<<endl;

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
