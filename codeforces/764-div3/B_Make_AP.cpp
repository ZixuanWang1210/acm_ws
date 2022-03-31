#include <bits/stdc++.h>
#define endl "\n"
#define debug(x) cout << #x << ": -----> " << x << endl;
// typedef long long ll;
// typedef unsigned long long ull;

using namespace std;

void sol(){
    int a[5];
    cin>>a[1]>>a[2]>>a[3];
    int d1=a[2]-a[1];
    int c1=a[2]+d1;
    
    if(c1%a[3]==0&&c1&&c1/a[3]>0){
        cout<<"YES"<<endl;
        return ;
    }
    int d2=a[3]-a[1];
    int b2=(a[3]+a[1])/2;
    if(b2%a[2]==0&&(a[3]+a[1])%2==0&&b2&&b2/a[2]>0){
        cout<<"YES"<<endl;
        return ;
    }
    int d3=a[3]-a[2];
    int a2=a[2]-d3;
    if(a2%a[1]==0&&a2&&a2/a[1]>0){
        cout<<"YES"<<endl;
        return ;
    }
    cout<<"NO"<<endl;
}   

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        sol();
    }
    

    return 0;
}
