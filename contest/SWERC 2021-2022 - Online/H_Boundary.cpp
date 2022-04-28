#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;
// #define int long long

using namespace std;

// void sol(){
//     int a,b; cin>>a>>b; 
//     if(a>b) swap(a,b);
//     if(a==b){
//         cout<<"3 1 2 "<<a-1<<endl;
//         return;
//     }
//     else if(a+2==b){
//         cout<<"3 1 2 "<<a<<endl;
//         return;
//     }
//     else cout<<"2 1 2"<<endl;
//     return;

// }

set<int> ans;
void add(int x){
    for(int i=1;i<=x/i;i++){
        if(x%i==0){
            ans.insert(i);
            ans.insert(x/i);
        }   
    }
}

void sol(){
    ans.clear();
    int a,b; cin>>a>>b; 
    add(__gcd(a-1,b-1));
    add(__gcd(a,b-2));
    add(__gcd(a-2,b));
    add(__gcd(a-1,__gcd(b-2,b)));
    add(__gcd(a-2,__gcd(a,b-1)));
    cout<<ans.size()<<' ';
    for(auto x:ans){
        cout<<x<<' ';
    }
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}
