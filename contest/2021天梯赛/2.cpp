#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k,m;
    cin>>n>>k>>m;
    int res=n-k*m;
    res=max(res,0);
    cout<<res<<endl;
    

    return 0;
}
