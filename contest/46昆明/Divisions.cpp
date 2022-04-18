#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

void sol(){
    int k; cin>>k;
    if(k==0){
        cout<<6<<endl<<"1 2 1 3 1 2"<<endl;
    }
    else if(k==1){
        cout<<6<<endl<<"1 1 4 5 1 4"<<endl;
    }
    else{
        k-=2;
        vector<int> a;
        a.push_back(1);
        int cnt=1;
        for(int i=0;i<=27;i++){
            if(k>>i&1){
                a.push_back(++cnt);
                cnt++;
                for(int j=1;j<=i;j++){
                    a.push_back(cnt);
                }
            }
        }
            cout<<a.size()<<endl;
            for(auto x:a){ cout<<x<<' ';};
        cout<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; _=1;
    while(_--){
        sol();
    }

    return 0;
}
