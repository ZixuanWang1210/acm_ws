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

    int cnt=0;
    for(int i=1;i<=30;i++){
        if(is_prime(i)) cout<<i<<" ",cnt++;
        if(cnt%5==0) cout<<endl;
    }

    return 0;
}
