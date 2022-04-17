#include<bits/stdc++.h>
using namespace std;


bool get(int x){
    if(x==1) return false;
    if(x<=3) return true;
    for(int i=2;i<=x/i;i++){
        if(x%i==0) return false;
    }
    return true;
}

void sol(){
    int n,m; cin>>n>>m;
    int cnt=0;
    for(int p=n;p<=m;p++){
        if(!get(p)) continue;
        for(int q=p+1;q<=m;q++){
            if(!get(q)) continue;
            for(int r=q+1;r<=m;r++){
                if(!get(r)) continue;
                if(get(p*q+r)&&get(q*r+p)&&get(r*p+q)){
                    // cout<<p<<' '<<q<<' '<<r<<endl;
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<endl;

}

void debug(){
    int x; 
    while(cin>>x){
        cout<<get(x)<<endl;
    }

}

int main(){
    int t; t=1;
    while(t--) sol();
    // debug();
    
    return 0;
}