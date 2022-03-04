#include<bits/stdc++.h>
using namespace std;

void sol(){
    int n; cin>>n;
    n--;
    int k=n,cnt=0;
    while(k){
        k>>=1;
        cnt++;
    }
    cnt--;
    int tt=1<<cnt;
    // cout<<tt<<endl;
    // cout<<cnt<<endl;
    for(int i=1;i<=(1<<cnt)-1&&i<=n;i++){
        cout<<i<<' ';
    }
    cout<<0<<' ';
    for(int i=1<<cnt;i<=n;i++){
        cout<<i<<' ';
    }
    cout<<endl;
}

int main(){
    int _; cin>>_;
    while(_--){
        sol();
    }
    return 0;
}