#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;



void sol(){
    int res=0;
    int n; cin>>n;
    vector<int> v(2*n);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=j;k<=n;k++){
                if(v[i]+v[j]==v[k]){
                    res++;
                }
            }
        }
    }
    cout<<res<<endl;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }
    

    return 0;
}
