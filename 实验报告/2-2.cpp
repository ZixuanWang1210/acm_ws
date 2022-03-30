#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x){
    if(x<2) return false;
    for(int i=2;i<=x/i;i++){
        if(x%i==0) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int x;
    int cnt=0;
    while(cin>>x){
        // cnt++;
        if(is_prime(x)) cout<<x<<" ",cnt++;
        // else cout<<"No ";
        if(cnt%5==0) cout<<endl;
    }

    return 0;
}
