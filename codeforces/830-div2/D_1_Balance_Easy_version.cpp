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
    map<int,int> mp;
    map<int,int> last;
    mp[0]=1;
    for(int i=1;i<=n;i++){
        char op; cin>>op;
        int x; cin>>x;
        if(op=='+') mp[x]=1;
        else{
            int cur=last[x];
            while(mp[cur]) cur+=x;
            last[x]=cur;
            cout<<cur<<endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int _=1;
    // cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
