#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;


void sol(){
    int n; cin>>n;
    vector<int> v(2*n);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    cout<<*max_element(v.begin()+1,v.begin()+1+n)-*min_element(v.begin()+1,v.begin()+1+n)<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--){
        sol();
    }

    return 0;
}
