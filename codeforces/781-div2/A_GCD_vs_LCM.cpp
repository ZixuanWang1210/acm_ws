#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n;
    cin>>n;
    if(n==4){
        cout<<"1 1 1 1"<<endl;
    }
    else cout<<1<<' '<<n-3<<' '<<1<<' '<<1<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--) sol();

    return 0;
}
