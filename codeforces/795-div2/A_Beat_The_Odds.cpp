#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1);
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(v[i]%2==0) cnt1++;
        else cnt2++;
    }
    cout<<min(cnt1,cnt2)<<endl;

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
