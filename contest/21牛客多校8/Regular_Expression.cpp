#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define all(x) x.begin()+1,x.end()
#define _all(x) x.begin(),x.end()
#define mod 1000000007
#define ll long long
// #define int long long

using namespace std;

void sol(){
    string s; cin>>s;
    int len=s.length();

    bool ok=true;
    for(int i=0;i<s.length();i++){
        if(s[i]!=s[0]){
            ok=false;
        }
    }

    



    if(len==1) cout<<"1 2"<<endl;
    // else if(len>2) cout<<"2 1"<<endl;
    // else cout<<"2 6"<<endl;
    else if(len==2){
        if(ok) cout<<"2 8"<<endl;
        else cout<<"2 6"<<endl;
    }
    else{
        if(ok) cout<<"2 3"<<endl;
        else cout<<"2 1"<<endl;
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
