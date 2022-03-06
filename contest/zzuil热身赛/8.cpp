#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
#define int long long 
using namespace std;



signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int res=1;
    int sum=1;
    int n; cin>>n;
    for(int i=2;i<=n;i++){
        res*=i;
        sum+=res;
    }
    cout<<sum;
    

    return 0;
}
