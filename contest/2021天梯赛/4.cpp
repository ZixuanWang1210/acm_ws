#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n,m;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        double x; cin>>x;
        if(x<m){
            cout<<"On Sale! "<<fixed<<setprecision(1)<<x<<endl;
        }
    }
    

    return 0;
}
