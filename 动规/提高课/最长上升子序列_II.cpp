#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    vector<int> stk;
    stk.push_back(v[0]);

    for(int i=1;i<n;i++){
        if(v[i]>stk.back()){
            stk.push_back(v[i]);
        }
        else *lower_bound(stk.begin(),stk.end(),v[i])=v[i];
    }

    cout<<stk.size()<<endl;
    

    return 0;
}
