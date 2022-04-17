#include<bits/stdc++.h>
using namespace std;

int get(int x){
    int res=0;
    while(x){
        int t=x%10;
        res+=t;
        x/=10;
    }
    return res;
}

void sol(){
    int x; cin>>x;
    int re=-1;
    for(int i=2;i<=9;i++){
        int tt; tt=x*i;
        if(re==-1) re=get(tt);
        else{
            if(re!=get(tt)){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<re<<endl;
    return;
}

int main(){
    int t; cin>>t;
    while(t--) sol();
    
    return 0;
}