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
    for(int i=1;i<=n;i++) cin>>v[i];

    int cnt=0;
    for(int i=n-1;i>=1;i--){
        while(v[i]>=v[i+1]){
            cnt++;
            v[i]>>=1;
            if(v[i]==0&&v[i+1]==0){
                cout<<-1<<endl;
                return;
            }
        }
    }
    cout<<cnt<<endl;

}

signed main(){
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _=1;
    cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
