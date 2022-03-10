#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int n,k; cin>>n>>k;
    if(n==4&&k==3){
        cout<<-1<<endl;
        return;
    }
    // n--;
    // cout<<k<<endl<<endl;
    if(n-1==k){
        cout<<n-1<<' '<<n-2<<endl;
        cout<<n-3<<' '<<1<<endl;
        cout<<0<<' '<<2<<endl;
        for(int i=3;i<=(n-1)/2;i++){
            if(i==k||i==n-k-1||i==0||i==n-1){
                continue;
            }
            else{
                cout<<i<<' '<<n-i-1<<endl;
            }
        }
        
        
        return;
    }
    for(int i=0;i<=(n-1)/2;i++){
        if(i==k||i==n-k-1||i==0||i==n-1){
            continue;
        }
        else{
            cout<<i<<' '<<n-i-1<<endl;
        }
    }
    cout<<n-1<<' '<<k<<endl;
    if(k) cout<<0<<' '<<n-k-1<<endl;
    // cout<<endl<<endl;
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }
    

    return 0;
}
