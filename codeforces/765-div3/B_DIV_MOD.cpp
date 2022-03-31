#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

bool check(int x,int a,int r){
    if(x*a-1<r) return true;
    return false;
}

void sol(){
    int l, r, a;
    cin >> l >> r >> a;
    int x = r - r % a - 1;
    if(r % a != a - 1 && l <= x) cout << x / a + x % a << endl;
    else cout << r / a + r % a << endl;

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        sol();
    }
    

    return 0;
}
