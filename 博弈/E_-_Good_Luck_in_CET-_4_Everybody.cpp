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
    

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    int n;
    while(cin>>n){
        int cnt=0;
        while(n){
            if(n&1) cnt++;
            n>>=1;
        }
        if(cnt%2) cout<<"Kiki"<<endl;
        else cout<<"Cici"<<endl;
    }

    return 0;
}
