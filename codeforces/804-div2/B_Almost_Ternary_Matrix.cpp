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
    int n,m; cin>>n>>m;
    string s1,s2;
    int line=m/4;
    for(int i=1;i<=line;i++){
        s1+="1001";
    }
    int res=m-line*4;
    if(res) s1+="10";

    for(int i=1;i<=line;i++){
        s2+="0110";
    }
    if(res)  s2+="01";

    n/=2;
    for(int i=1;i<=n;i++){
        if(i&1){
            for(int i=0;i<s1.length();i++){
                cout<<s1[i]<<' ';
            }
            cout<<endl;
            for(int i=0;i<s2.length();i++){
                cout<<s2[i]<<' ';
            }
            cout<<endl;
        }
        else{
            for(int i=0;i<s2.length();i++){
                cout<<s2[i]<<' ';
            }
            cout<<endl;
            for(int i=0;i<s1.length();i++){
                cout<<s1[i]<<' ';
            }
            cout<<endl;
        }
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
