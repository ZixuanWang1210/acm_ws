#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define all(x) x.begin() + 1, x.end()
// #define ll long long
#define int long long

using namespace std;

void sol() {
    int a,b;
    cin>>a>>b;
    int ans=b-a;
    for(int i=0;i<ans;i++){
        if(((a+i)|b)==b){
            ans=i+1;
            break;
        }
    }
    for(int i=1;i<ans;i++){
        if((a|(b+i))==b+i){
            ans=i+1;
            break;
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int _ = 1;
    cin >> _;
    while (_--) {
        sol();
    }

    return 0;
}
