#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

int n;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }    
    cout<<*min_element(v.begin()+1,v.begin()+1+n)<<' '<<count(v.begin()+1,v.begin()+1+n,*min_element(v.begin()+1,v.begin()+1+n))<<endl;
    cout<<*max_element(v.begin()+1,v.begin()+1+n)<<' '<<count(v.begin()+1,v.begin()+1+n,*max_element(v.begin()+1,v.begin()+1+n))<<endl;

    return 0;
}
