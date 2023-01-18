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
    int n; cin>>n;
    int tot=n*n;

    int cost=0;
    int nn=n*n-1;
    while(nn--){
        string s; cin>>s;
        cost+=10;
        for(int i=0;i<4;i++){
            if(s[i]=='1') cost--;
            else if(s[i]=='2') cost++;
        }
        // cout<<cost<<endl;
    }
    cout<<10*n*n-cost<<endl;
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
