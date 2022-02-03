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
    if(n==0){
        cout<<0<<' '<<0;
    }
    else if(n==1){
        cout<<0<<' '<<0;
    }
    else if(n==2){
        cout<<1<<' '<<1;
    }
    else if(n==3){
        cout<<2<<' '<<3;

    }
    else{
        cout<<1<<' '<<n-1;
    }
    

    return 0;
}
