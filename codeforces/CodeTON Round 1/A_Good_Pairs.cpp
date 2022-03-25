#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n; cin>>n;
    vector<int> v(2*n);
    int fi=0,se=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];

    }
    // cout<<1<<' '<<1<<endl;
    fi=max_element(v.begin()+1,v.begin()+1+n)-v.begin();
    se=min_element(v.begin()+1,v.begin()+1+n)-v.begin();
    cout<<se<<' '<<fi<<endl;
    return;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _ ;cin>>_;
    while(_--){
        sol();
    }
    

    return 0;
}
