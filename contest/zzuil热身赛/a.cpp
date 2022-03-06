#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(__gcd(i,n)==1) cnt++;

    }
    // cout<<__gcd(15,3)<<' ';
    cout<<cnt<<endl;

    return 0;
}
