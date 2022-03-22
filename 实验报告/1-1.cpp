#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int x; cin>>x;
    if(x<1){
        cout<<x;
    }
    else if(x>=1&&x<10){
        cout<<2*x-1;
    }
    else{
        cout<<2*x-11;
    }

    return 0;
}
