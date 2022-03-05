#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll a[20];

int get(int x){
    int res=0;
    while(x){
        if(x&1) res++;
        x>>=1;
    }
    return res;
}

int biao(){
    a[1]=1;a[0]=0;
    for(int i=2;i<=15;i++){
        a[i]=a[i-1]*i;
    }
}

void sol(){
    int x; cin>>x;
    ll temp=0;
    for(int i=0;i<16;i++){
        if(i&(1<<i)){
            temp+=a
        }
    }
}

int main(){
    biao();
    int t; cin>>t;
    while(t--){
        sol();
    }

    return 0;
}