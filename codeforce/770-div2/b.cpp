#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

long long t,n,x,y;

void sol(){
    cin>>n>>x>>y;
    long long sum=0;
    for(int i=1;i<=n;i++){
        long long tt; cin>>tt;
        sum+=tt;
    }
    sum%=2,x%=2,y%=2;
    if(sum){
        x^=1;
    }
    if(x==y){
        cout<<"Alice"<<endl;
        return;
    }
    else{
        cout<<"Bob"<<endl;
        return;
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
