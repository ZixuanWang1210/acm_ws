#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
#define int long long

using namespace std;

void sol(){
    string s; cin>>s;
    int cnt1=0,cnt0=0;
    int res=s.length();
    int res1=5,res0=5;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1'&&i%2==0) cnt1++;
        else if(s[i]=='1'&&i%2==1) cnt0++;
        if(i%2==0) res1--;
        else if(i%2==1) res0--;
        if(cnt1+res1<cnt0){
            cout<<i+1<<endl;
            return;
        }
        if(cnt0+res0<cnt1){
            cout<<i+1<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;
    return;

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
