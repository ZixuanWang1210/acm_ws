#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int x; cin>>x;
    x%=2048;
    if(x<1024) cout<<x<<' ';
    else cout<<x-2048<<' ';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--)
    {
        sol();
    }

    return 0;
}
