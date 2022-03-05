#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
typedef long long ll;

// typedef unsigned long long ull;

using namespace std;

ll x,n;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>n;
    if(n>x){
        cout<<0;
        return 0;
    }
    cout<<x*n<<endl;
    

    return 0;
}
