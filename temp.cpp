//link:
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(),x.end()
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);
void sol(){
    ll x,y,z;
    cin>>x>>y>>z;
    if(x==z||y==z){
        cout<<0<<"\n";
    } else if(z&1){
        cout<<"-1\n";
    } else {
        ll k=(x+y)*2;
        int cnt=1;
        while(z){
            if(k>=z){
                cout<<cnt<<"\n";
                return ;
            } 
            k*=2;
            cnt++;
        }
    }
    
}
signed main(){
    IOS
    int qwq=1;
    cin>>qwq;
    while(qwq--)sol();
    return 0;
}   
