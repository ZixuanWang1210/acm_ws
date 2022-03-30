#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    set<int> s;
    for(int i=1;i<=n;i++){
        // cin>>v[i];
        int t; cin>>t;
        s.insert(t);
    }
    for(int i=0;;i++){
        if(s.count(i)==0){
            cout<<i<<endl;
            return 0;
        }
    }
    
    

    return 0;
}
