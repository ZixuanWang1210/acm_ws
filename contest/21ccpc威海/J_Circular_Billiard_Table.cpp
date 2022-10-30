// 若小球反射 n 次后回到原点，则 nα = k · 360°（k 为某个自然数）。
// 换言之，最小的 n 即为最小的 n 使得 360|nα，利用 gcd 算一下即可。

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
    int a,b; cin>>a>>b;
    swap(a,b);
    cout<<(180*a)/__gcd(b,180*a)-1<<endl;
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
