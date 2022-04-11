#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
const int mod=1e9+7;
using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(n+1);
    long long sum=1;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        v[i]%=mod;
        sum%=mod;
        sum*=v[i];
        sum%=mod;
    }
    cout<<sum<<endl;  

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    sol();
    

    return 0;
}
