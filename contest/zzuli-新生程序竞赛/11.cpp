#include<bits/stdc++.h>
#define int long long
using namespace std;

const int P=1000000007;
// int n;

void sol(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a>=30&&b>=14&&c>=12){
        cout<<"Yes"<<endl;
    }
    else if(1.5*a>=30&&b>=14&&c>=12){
        cout<<"ulii"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
    int _; cin>>_;
    while(_--){
        sol();
    }

    return 0;
}