#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
using namespace std;

int t,n,k;

void sol(){
    cin>>n>>k;
    if(k!=1&&n%2){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    int now=1;
    for(int i=1;i<=(n+1)/2;i++){
        for(int j=1;j<=k;j++){
            cout<<now<<" ";
            now+=2;
        }
        cout<<endl;
    }
    now=2;
    for(int i=1;i<=(n)/2;i++){
        for(int j=1;j<=k;j++){
            cout<<now<<" ";
            now+=2;
        }
        cout<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        sol();
    }
    

    return 0;
}
