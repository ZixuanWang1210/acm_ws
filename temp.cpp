#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

long long t,n,x,y;
int a[100010];

void sol(){
    long long sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
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
        cin>>n>>x>>y;
        sol();
    }
    

    return 0;
}
