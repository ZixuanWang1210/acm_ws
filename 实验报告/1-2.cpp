#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;



int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    vector<int> v;
    for(int i=0;i<4;i++){
        int t; cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    for(auto x:v){
        cout<<x<<' ';
    }
    

    return 0;
}
