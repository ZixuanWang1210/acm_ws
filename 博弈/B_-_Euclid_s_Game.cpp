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

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    int a,b;
    while(cin>>a>>b,a||b){
        int flag=0;
        while(1){
            if(b>a) swap(a,b);
            if(a%b==0||a/b>1) break;
            a=a%b;
            flag^=1;
        }
        if(!flag) cout<<"Stan wins"<<endl;
        else cout<<"Ollie wins"<<endl;
    }

    return 0;
}
